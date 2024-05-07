# Authors


[Justin Im](https://github.com/justin-h-im)

[Athena Nelson](https://github.com/thena-ay)

[Marcus Hsieh](https://github.com/MarcusHsieh)

[Vimal Selvarajan](https://github.com/vselv001)

## Game name ideas
♔ **Clash of Chess** ♕ 

♔ **Chess Crusaders** ♕

♔ **Chess++** ♕



Game Description
================

## Why is it important or interesting to you?
We find that chess is a repeatable and boring game that has not received any meaningful updates in the past 2000 years. We are also bad at chess. 
We will attempt to add new mechanics to a classic game that are reminiscent of turn-based style combat.
We hope to put a twist on chess that will intrigue younger generations of players. 

## What languages/tools/technologies do you plan to use?
- C++
- Possibly the SDL library

## What will be the input/output of your project?
### Output
- Menu Select screen.
- Chess board after each move.
- List of possible moves for beginners. 
### Input:
- Location of the piece to be moved.
- Coordinates of the new location.
- Prompts for actions for the combat scenario.

  1. **Attack**
      - Normal attack (with RNG mechanic)
      - Each piece has a unique ability
  2. **Flee**
      - The player fleeing is forced to use their turn to move their piece in battle a new location

## What are the features that the project provides?
- 2-player local multiplayer chess

  - Ascii art to represent the board and pieces

  - Each player gets a turn to choose a piece to move
    - Touch-move chess (once a player touches(selects) a piece they must move or capture if it is legal to do so) 
    
  - The goal is the same as normal chess, so each player must try to checkmate the other player’s king
#
- Everytime a player attempts to capture, the two players enter a turn-based combat scenario.
  - Each player chooses a combat ability innate to their pieces, and effectiveness of attack is determined by a dice roll.
    - The players will see the result of this dice roll.
    - D20 for accuracy
      - Whether or not the attack will hit is determinant on an RNG mechanic.
      - The players will see a message that displays “hit” or “miss”.
      
    - D20 for attack
      - Damage is scaled to the piece’s maximum attack. 
#
- If a pawn reaches the end of the board, they will be able to swap out their piece based on RNG
  - This will be determined by a D6 roll, with each number representing a possible piece
    - Pawn -> (Pawn, Bishop, Knight, Rook, Queen, King)

  - If the pawn rolls to be another pawn, it will move backwards.

Code Analysis
=============

- Each piece inherits from an abstract “piece” class
- Each piece has a move function that calculates the possible moves by adding/subtracting from its coordinates (moves, attacks)
- Computer calculates all possible moves for selected piece and check all possible moves (2 separate checks)


## Board Controls
### Move:
- If newCoord has a piece on it, do nothing
- If newCorod is empty, add to moveArr
### Attack:
- If newCoord has piece on it, add to attackArr
- If newCoord is empty, do nothing

> *Show list of moves and attacks based on moveArr and attackArr*
>> If the user selects an invalid coordinate, a notice will be given and they will be prompted to choose another location. (Repeat until user picks valid location)
#

### Special case: 
Pawn needs a different check for move and attack 
>i.e. pawn on (1, 1) -> can move to (1,2) -> can attack (0, 2), (2, 2)
  - Pawn move = (+0, +1)
  - Pawn attack = (-1, +1), (+1, +1)

### All other piece’s moves overlap with their attacks
Calculated through coordinates, these are the modifying values which affect the piece's current coordinate

The computer uses these modifying values to calculate potential move/attack coordinates and runs a check on these new coordinates for their validity based on the **Board Controls** section

- Bishop = (+1\*n, +1\*n), (-1\*n, +1\*n), (+1\*n, -1\*n), (-1\*n, -1\*n)
- Knight = (-1, +2), (+1, +2), (+2, +1), (+2, -1), (+1, -2), (-1, -2), (-2, -1), (-2, +1), 
- Rook = (+/-1\*n, +0), (0, +/-1\*n)
- Queen = [bishop + rook combined] 
- King = (-1, +1), (+0, +1), (+1, +1), (+1, +0), (+1, -1), (+0, -1), (-1, -1), (-1, 0)

For Every Move
--------------
1. Is that location on the board?
1. Is there a piece at that location?
1. Is it your piece?
1. Is this a legal move?
1. Can the piece be moved like this? 
1. Does moving that piece put your king in check?
1. Does moving that piece put the opponent in check?

### User Interface Specifications
![CombatChessUIRoutine](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/e9ac340d-1acb-4b75-a162-2756cbaa4cb1)

### UML Diagram
![CS100FinalProject drawio (3)](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/147112330/014a7bf7-30c2-4827-9dac-a8d1599fa716)

### Class Descriptions
The Game class will be the board and control the turns. Since it is the board, it is responsible for setting up the board which holds pointers to pieces in an 8 by 8 2D array and displaying the visuals. Along with that it will also control what phase the game is in (i.e. player turn, combat, and end game when king hp is 0).
For the chess pieces there is a base class called Piece which contains a color, the coordinates of the piece, the type of piece it is, and the health of the piece for combat. The color of the piece and the pieceType have separate enums to make it simpler for identifying pieces for interactions. It also has cooresponding getters and setters. Along with the base class there are 6 derived classes for each of the unique chess piece types. These are responsible for the pieces specific movements and what they do in encounters.

