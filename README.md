```markdown
# So Long

So Long is a 42 School project where you create a simple 2D game using the MinilibX graphics library. The goal is to build a small game engine that handles rendering, user input, and basic game mechanics like movement, collisions, and win/lose conditions.

This project is a great introduction to game development and helps you understand the fundamentals of game loops, state management, and graphical programming.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Contributing](#contributing)
- [License](#license)

## About

The objective of **So Long** is to create a simple game where the player can move around a map, collect items, and reach an exit point. The game should include:

- A map loaded from a file.
- Player movement and interaction with the environment.
- Collision detection (e.g., walls blocking movement).
- Win/lose conditions based on collecting items and reaching the exit.

This project uses **C** and the **MinilibX** library for rendering graphics and handling user input.

## Features

- **Map Parsing**: Load maps from `.ber` files.
- **Player Movement**: Move the player character using keyboard controls.
- **Collision Detection**: Prevent the player from walking through walls.
- **Item Collection**: Collect items scattered across the map.
- **Win/Lose Conditions**: Reach the exit after collecting all items to win, or lose if certain conditions are met.
- **Animations**: Basic animations for player movement and interactions.

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/so_long.git
   cd so_long
   ```

2. Install dependencies (MinilibX):

   - On macOS, MinilibX is typically pre-installed or can be installed via Homebrew.
   - On Linux, you may need to install `libmlx` and `libxext-dev`.

3. Compile the project:

   ```bash
   make
   ```

4. Run the program:

   ```bash
   ./so_long maps/map.ber
   ```

   Replace `map.ber` with the path to your map file.

## Usage

To play the game, ensure you have a valid `.ber` map file. The map file should follow these rules:

- The map must be rectangular.
- It must contain exactly one player (`P`), one exit (`E`), and at least one collectible item (`C`).
- Walls (`1`) must surround the entire map.
- Empty spaces are represented by `0`.

Example map (`maps/map.ber`):

```
1111111111
1000000C01
1000110001
10000000P1
11111111E1
```

Run the game:

```bash
./so_long maps/map.ber
```

## Controls

- **W/A/S/D or Arrow Keys**: Move the player up, left, down, or right.
- **ESC**: Exit the game.

Made with ❤️ for 42 School.

```