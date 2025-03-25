# 🚀 Cub3D - 3D Raycasting Engine

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

> A 3D maze renderer using raycasting techniques inspired by Wolfenstein 3D

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Demo](#demo)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [Contact](#contact)

## 📖 Overview

Cub3D is a graphics project that implements a simple 3D game engine using raycasting techniques. The project renders a 3D maze from a 2D map, allowing players to navigate through the environment with a first-person perspective. It's inspired by the groundbreaking game Wolfenstein 3D and developed as part of the 42 school curriculum.

---

## ✨ Features

- ✅ Textured walls with different textures for each wall direction (North, South, East, West)
- ✅ Player movement (forward, backward, left, right) and camera rotation
- ✅ Collision detection with walls
- ✅ Map parsing from configuration files (.cub)
- ✅ Customizable resolution and textures
- ✅ Minimap display
- ✅ Animated sprites
- ✅ Openable doors

---

## 🎮 Demo

![Cub3D Demo](screenshots/walkthrough.gif)

---

## 🔧 Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/ondbeh/cub3d.git
   ```
2. Navigate to the project directory:
   ```bash
   cd cub3d
   ```
3. Compile the project:
   ```bash
   make
   ```

### Requirements

- GCC compiler
- Make
- MLX42 library (included ad a submodule)
- X11 libraries (for Linux) or Cocoa (for macOS)

---

## 📚 Usage

Run the program with a map file:

```bash
./cub3d maps/map.cub
```

### Map Configuration

The `.cub` file should contain:

### Map Symbols

| Symbol | Description                |
| ------ | -------------------------- |
| `1`    | Wall                       |
| `0`    | Walkable space             |
| `NSEW` | Player starting position   |
| `D`    | Door (closed)              |
| ` `    | Empty space (not walkable) |

---

## 🤝 Contributing

- [Konrad Muhlbauer](https://github.com/Komu211)
- [Ondřej Běhávka](https://github.com/ondbeh)

---

## 📞 Contacts

- [GitHub](https://github.com/ondbeh)
- [Email](mailto:ondbeh@gmail.com)
- [LinkedIn](https://www.linkedin.com/in/ondrej-behavka/)
