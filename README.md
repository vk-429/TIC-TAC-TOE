# Tic Tac Toe Game

This repository contains a console-based Tic Tac Toe game implemented in C. The game allows you to play in different modes: against a friend, against a smart computer, or against an evil computer.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Modes](#game-modes)
  - [Play with a Friend](#play-with-a-friend)
  - [Play with Smart Computer](#play-with-smart-computer)
  - [Play with Evil Computer](#play-with-evil-computer)
- [Contributing](#contributing)
- [License](#license)

## Features

- Play against a friend in two-player mode.
- Play against a smart computer that makes strategic moves.
- Play against an evil computer that plays unfairly to ensure its victory.
- Color-coded console text for a better user experience.

## Installation

To run this project, you need to have a C compiler installed on your system. Follow these steps to compile and run the program:

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/your-repo-name.git
    ```

2. Navigate to the project directory:
    ```sh
    cd your-repo-name
    ```

3. Compile the program:
    ```sh
    gcc -o tic_tac_toe tic_tac_toe.c -std=c99
    ```

4. Run the executable:
    ```sh
    ./tic_tac_toe
    ```

## Usage

After running the executable, you will be presented with a menu to choose the game mode. Follow the on-screen instructions to play the game.

## Game Modes

### Play with a Friend

- Select the option to play with a friend.
- Enter the names of both players.
- Take turns to place your mark (`O` for player 1 and `X` for player 2) on the board.
- The game continues until one player wins or the board is full (draw).

### Play with Smart Computer

- Select the option to play with the smart computer.
- Enter your name.
- Take turns to place your mark (`O`) on the board.
- The computer will play strategically to either win or block your moves.

### Play with Evil Computer

- Select the option to play with the evil computer.
- Enter your name.
- Take turns to place your mark (`O`) on the board.
- The computer will play unfairly to ensure its victory.

## Contributing

If you want to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/your-feature`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add some feature'`).
5. Push to the branch (`git push origin feature/your-feature`).
6. Open a pull request.

