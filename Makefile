include srcs.mk

# Name of the library
NAME		=	cub3D

# Compiler and flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Wunreachable-code -I.
DEBUG_FLAGS	=	-g  -fsanitize=address #-fcolor-diagnostics -fansi-escape-codes
RM			=	rm -f
INCLUDES	=	-Iincludes

# Directories
SRC_DIR		=	src
OBJ_DIR		=	obj
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft
MLX42_DIR	=	./MLX42
MLX42		=	$(MLX42_DIR)/build/libmlx42.a



# Detect the operating system
UNAME_S := $(shell uname -s)

# Set MLX42_FLAGS based on the operating system, also catch MAC arm processors
ifeq ($(UNAME_S), Linux)
    MLX42_FLAGS = -L$(MLX42_DIR)/build -lmlx42 -lGL -lX11 -lXrandr -lXi -lXxf86vm -lXinerama -lXcursor
else ifeq ($(UNAME_S), Darwin)
    MLX42_FLAGS = -L$(MLX42_DIR)/build -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit
endif

GLFW_PATH_HOMEBREW_ARM = /opt/homebrew/opt/glfw
GLFW_PATH_HOMEBREW_INTEL = /usr/local/opt/glfw
GLFW_PATH_SYSTEM = /usr/local

ifneq (,$(wildcard $(GLFW_PATH_HOMEBREW_ARM)/lib/libglfw.dylib))
    GLFW_PATH = $(GLFW_PATH_HOMEBREW_ARM)
else ifneq (,$(wildcard $(GLFW_PATH_HOMEBREW_INTEL)/lib/libglfw.dylib))
    GLFW_PATH = $(GLFW_PATH_HOMEBREW_INTEL)
else
    GLFW_PATH = $(GLFW_PATH_SYSTEM)
endif

# Source files and corresponding object files

OBJS 		= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Rules
all: $(NAME)

# Link object files and libft to create the final executable
$(NAME): $(MLX42) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX42_FLAGS) -lm -L$(GLFW_PATH)/lib -lglfw
	@echo "Compiling $(NAME) project"

debug: $(MLX42) $(LIBFT) $(OBJS)
	@$(CC) $(DEBUG_FLAGS) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX42_FLAGS) -lm -L$(GLFW_PATH)/lib -lglfw
	@echo "Compiling $(NAME) project with debug flags"

# Compile source files into object files in the obj/ folder
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create the obj/ directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Creating folder for object files"

# Build the libft library by calling its Makefile
$(LIBFT):
	@echo "Compiling libft"
	@git submodule update --init --recursive -q
	@$(MAKE) -C $(LIBFT_DIR) all

# Build the MLX42 library
$(MLX42):
	@echo "Compiling mlx42..."
	@git submodule update --init --recursive -q
	@if [ ! -d $(MLX42_DIR)/build ]; then mkdir -p $(MLX42_DIR)/build; fi
	@cd $(MLX42_DIR)/build && cmake .. && make -j4

# Clean object files from both $(NAME) and libft
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Deleting libft objects"
	@$(MAKE) -C $(MLX42_DIR)/build clean
	@echo "Deleting MLX42 objects"
	@rm -rf $(OBJ_DIR)
	@echo "Deleting $(NAME) objects"

# Full clean: also remove the executable and libft objects
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Deleting libft.a"
	@$(RM) $(NAME)
	@echo "Deleting $(NAME) executable"

# Rebuild everything
re: fclean all

# Clean cub3d objects
cleancub:
	@rm -rf $(OBJ_DIR)
	@echo "Deleting $(NAME) objects"

# Rebuild cub3d
recub: cleancub all

# Norm rule
norm:
	@echo "Norminette for libft and cub3d:"
	@-norminette src libft includes | grep "Error" || true

# PHONY prevents conflicts with files named like the targets
.PHONY: all clean fclean re
