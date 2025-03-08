SRCS		=	main.c \
				init.c \
				exit_error.c \
				exit_success.c \
				cleanup.c \
				mlx_preparation.c \
				key_hook_control.c \
				draw_scene.c \
				calculate_rays.c \
				draw_rays.c \
				movement_handlers.c \
				rotation_handlers.c \
				load_texture.c \
				calculate_fps.c \
				mouse_hook_control.c \
				loop_hook_control.c \
				vector_size.c \
				minimap.c \
				parse_file.c \
				validation.c \
				ft_isspace.c \
				free_split.c \
				map_ll_to_array.c \
				flood_fill_and_bounds_check.c \
				draw_sprites.c \
				parse_sprite.c \
				door_logic.c \
				parse_file1.c \
				draw_sprites_helper.c

VPATH		=	src/ \
				src/init/ \
				src/exit/ \
				src/key_hooks/ \
				src/draw/ \
				src/utils/ \
				src/parsing/