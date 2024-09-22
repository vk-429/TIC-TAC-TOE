
# Advanced TIC TAC TOE

This repository contains an advanced implementation of the classic Tic Tac Toe game in C, featuring multiple gameplay modes, including player vs. player and player vs. AI. The AI can be customized to either play strategically (smart mode) or unfairly (evil mode), providing a diverse gaming experience. Additionally, color-coded console text enhances the visual feedback of the game.

## Table of Contents

- [Key Features](#key-features)
- [Installation Guide](#installation-guide)
- [How to Play](#how-to-play)
- [Game Modes Explained](#game-modes-explained)
  - [Player vs Player Mode](#player-vs-player-mode)
  - [Smart Computer Mode](#smart-computer-mode)
  - [Evil Computer Mode](#evil-computer-mode)
- [Console Color Scheme](#console-color-scheme)
- [Code Overview](#code-overview)
- [Contributing to the Project](#contributing-to-the-project)
- [License](#license)

## Key Features

- **Multiple AI Behaviors**: Play against a smart computer that anticipates your moves, or an evil computer that manipulates the game for its own benefit.
- **Color-Coded Gameplay**: The game interface leverages color to differentiate between moves, prompts, warnings, and outcomes, enhancing the player's visual experience.
- **Modular Design**: Each function in the game is modular and focused, making it easy to understand, modify, or extend for future functionality.
- **Console Compatibility**: Designed to work in a variety of terminal environments with minimal dependencies beyond a standard C compiler.
- **Cheat Detection**: Special modes where the AI can subtly manipulate the board to favor its own moves, offering a challenge for observant players.

## Installation Guide

To set up and run this project, follow the steps below:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/tic-tac-toe-advanced.git
   ```
   
2. **Navigate to the Project Directory**:
   ```bash
   cd tic-tac-toe-advanced
   ```

3. **Compile the Source Code**:  
   To compile the game, use any C compiler that supports C99 or later. For example:
   ```bash
   gcc -o tic_tac_toe game_screen_normal.c game_screen_computer.c computers_turn.c main.c -std=c99
   ```

4. **Run the Game**:
   After compilation, run the game using:
   ```bash
   ./tic_tac_toe
   ```

## How to Play

Upon starting the program, you'll be prompted with a menu to choose from different game modes. Based on your selection, you'll either play against another player or the computer.

### Basic Controls:
- **Player 1** and **Player 2** take turns marking the grid. The grid coordinates are entered as numbers (1-9) corresponding to different cells.
- **Objective**: Align three of your marks (`O` or `X`) either horizontally, vertically, or diagonally before your opponent.

## Game Modes Explained

### Player vs Player Mode

- In this mode, two human players can challenge each other on the same computer.
- Players take turns entering their moves, and the game alternates between player `O` and player `X`.
- The first player to align three marks wins, or the game ends in a draw if the board is filled without a winner.

### Smart Computer Mode

- In this mode, you’ll compete against a strategic AI.
- The smart computer evaluates the game board using basic algorithms such as **Minimax**, choosing optimal moves to block the player or win the game.
- This mode is ideal for players looking to practice against an AI that doesn’t cheat but still provides a significant challenge.

### Evil Computer Mode

- This mode takes the competition to another level by introducing a cheating AI.
- The evil AI is designed to modify the board behind the scenes, skewing the game in its favor and ensuring a near-certain victory.
- Can you outsmart a computer that bends the rules? Test your observation skills here!

## Console Color Scheme

To improve the gaming experience, the game uses a **color-coded system** for different elements:

- **Player O Moves**: Displayed in **white**.
- **Player X Moves**: Displayed in **red**.
- **Game Prompts**: Displayed in **green** for instructions and general flow.
- **Error Messages**: Displayed in **yellow**, indicating invalid moves or actions.
- **Winning/Draw Messages**: Displayed in **green** for a clean victory, and **red** if the evil computer cheats you out of a win.

```c
// Example Color Definitions
#define BLUE_COLOR_TEXT SetConsoleTextAttribute(hConsole, 9);
#define RED_COLOR_TEXT SetConsoleTextAttribute(hConsole, 12);
#define GREEN_COLOR_TEXT SetConsoleTextAttribute(hConsole, 2);
#define YELLOW_COLOR_TEXT SetConsoleTextAttribute(hConsole, 14);
```

## Code Overview

This project is organized into modular components:

- **main.c**: The entry point of the application, managing the overall flow of the game.
- **game_screen_normal.c**: Handles gameplay logic for the Player vs Player mode.
- **game_screen_computer.c**: Manages the logic for AI-based modes (smart and evil).
- **computers_turn.c**: Contains logic for the computer's turn, including strategies for the smart and evil modes.
- **game_helpers.c**: A utility file with helper functions for printing the board, validating moves, and checking game state.
  
This modular approach enables easy debugging and future expansions. Adding new AI behaviors or additional features will require minimal changes to the core structure.

## Contributing to the Project

Contributions are welcome! If you'd like to contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/some-feature`).
3. Commit your changes (`git commit -am 'Add some feature'`).
4. Push to the branch (`git push origin feature/some-feature`).
5. Open a pull request to discuss and review your changes.

We encourage contributions that add new AI modes, improve the UI, or optimize the game engine.

