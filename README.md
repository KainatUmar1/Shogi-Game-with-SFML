# Shogi-Game-with-SFML

## Overview
Welcome to another Shogi Game project! This is a C++ implementation of the traditional Japanese board game, Shogi. Shogi, also known as Japanese chess, is a two-player strategy game that offers deep strategic gameplay with its unique set of rules and piece movements.

## Features
- **Full Shogi Rules Implementation**: Experience the authentic gameplay of Shogi with all its traditional rules.
- **Enhanced Interface with SFML**: A visually appealing graphical interface built using SFML (Simple and Fast Multimedia Library) for better user experience.
- **Object-Oriented Programming (OOP)**: The game is structured using OOP principles for maintainability and scalability.
- **Piece Movement and Capture Mechanics**: Accurate simulation of piece movements and capture mechanics.
- **Visual Board Display**: Clear graphical board display using SFML to easily follow the game state.
- **Pieces Legalities**: When a player clicks a piece, all legal moves for that piece are highlighted. If another piece is clicked, the previously highlighted blocks are unhighlighted. This feature helps players see possible moves and strategize better.
- **Game State Saving**: The game automatically saves the last played game state in a file named `text1.txt`, allowing you to resume your game from where you left off.

## Files
- **Bishop.cpp / Bishop.h**: Implementation and header files for the Bishop piece.
- **Board.cpp / Board.h**: Implementation and header files for the game board.
- **Chess.cpp / Chess.h**: General chess-related functions and definitions.
- **King.cpp / King.h**: Implementation and header files for the King piece.
- **Knight.cpp / Knight.h**: Implementation and header files for the Knight piece.
- **Pawn.cpp / Pawn.h**: Implementation and header files for the Pawn piece.
- **Piece.cpp / Piece.h**: Base class for all pieces.
- **Player.cpp / Player.h**: Implementation and header files for player-related functionalities.
- **Queen.cpp / Queen.h**: Implementation and header files for the Queen piece.
- **Rook.cpp / Rook.h**: Implementation and header files for the Rook piece.
- **Utility.cpp / Utility.h**: Utility functions and definitions used throughout the project.
- **Shogi-game-using-SFML.cpp**: The main source code file containing the entry point of the Shogi game.
- **text.txt**: A sample file showcasing the representation of a Shogi game state.
- **text1.txt**: File where the last played game state is saved.

## Game State Representation
- The `text.txt` file includes an example of the Shogi board state.
- The `text1.txt` file saves the last played game state, allowing you to continue your game from the last move made.

## Getting Started

### Prerequisites
Before you begin, ensure you have the following installed:
- A C++ compiler (e.g., g++)
- SFML library

### Compilation
Compile the Shogi game on your compiler.

### Running the Game
After compiling, you can start the game by running it.

### Gameplay
Upon starting the game, you'll be prompted to input moves for each player alternately. The board will be displayed using the SFML interface after each move, showing the updated game state. The game continues until one player achieves checkmate.

## Author
**Kainat Umar** - *Developer of this Console-Based Shogi Game project with enhanced SFML interface.*
