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

## User Interface Specifications
### Navigation Diagram
The Menu Screen presents the user with three options. They may begin the game, review the game manual, or quit the game.  
The Select Piece Screen is the same for both users. The user is prompted to choose the location of the piece that they want to move.  
The Move Piece Screen is also the same for both users. The user is prompted to choose the new location of the piece that they want to move.  
The Combat Scenario Screen activates based on whether or not the new location is occupyed by an opposing piece. The screen features the white piece on the left and the black piece on the right, with their healthbars listed underneath each piece.  
The Combat Move Screens are the same for both users, appearing based on alternating turns. The screen lists possible moves that the user can take to deal damage to the opposing piece. The screen then changes for the opposing player, since the fighting pieces may have differing movesets.  
The Game Over Screen presents the user with a "GAME OVER" message. Underneath, there is a statement that declares victory to the winning player.  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/07d154ea-4a2a-4514-9b65-9855f05291b1)
### Screen Layouts
Combat Chess is entirely terminal run. As such, the graphical interface is done entirely throught text and ASCII characters. User input is typically done through numerical input.
Menu: Presents the user with options to begin the game, review the game manual, or quit the game.  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/24bc81f2-dc31-443e-9d18-4f89ccc4186c)  
Display User Guide: Presents the user with a user guide in terminal. The user may press "q" to quit.  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/05f2702e-6a9e-44da-a8ee-c194c0e8d4cc)  
Select Piece: Prompts the user to choose the location of the piece to be moved.  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/6f93570d-6a5c-4c8a-be86-155ec31ee861)  
Move Piece: Prompts the user to choose the new location of the selected piece.  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/43010332-6722-4239-8e94-60ad777b562e)  
Combat Scenario: Introduces the combat scenario with the dueling pieces.  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/c03277c9-3928-4ffd-88ce-94d5af870372)
Combat Move: Prompts both users for moves and performs combat actions based on the user turn and their chosen input.  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/79a8ae7a-cffa-4753-ac7a-ef8d259cc9c4)  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/c207936a-d96b-4043-a494-2f2de10b956e)  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/6262995b-7590-498d-8c19-62685e872229)  
Game Over: Display a "GAME OVER" screen and declare the victor of the game. 
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/6356b397-ad4e-4c96-b670-949561212365)  
UNICODE courtesy of https://www.unicode.org/charts/PDF/U2600.pdf.  

### UML Diagram
![UML drawio](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/166081771/253fd69c-3e56-42ce-9a0c-1afc299ce382)


### Output Screenshots
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/c90772c5-1666-4995-b6bb-1244e8931ab3) ![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/008c798b-2712-40ce-a551-a9fa1f5fda55)  
![image](https://github.com/cs100/final-project-mhsie026-jim023-anels048-vselv001/assets/93964548/95adfb87-03f6-4b2c-a4c1-bec705582e4e)  

### Class Descriptions
The Game class will be the board and control the turns. Since it is the board, it is responsible for setting up the board which holds pointers to pieces in an 8 by 8 2D array and displaying the visuals. Along with that it will also control what phase the game is in (i.e. player turn, combat, and end game when king hp is 0).
For the chess pieces there is a base class called Piece which contains a color, the coordinates of the piece, the type of piece it is, and the health of the piece for combat. The color of the piece and the pieceType have separate enums to make it simpler for identifying pieces for interactions. It also has cooresponding getters and setters. Along with the base class there are 6 derived classes for each of the unique chess piece types. These are responsible for the pieces specific movements and what they do in encounters.

### Class Description SOLID Updates
In the previous phase the class diagram for this project had several violations of SOLID principles. The main violation was a violation of the single responsibility principle by the Game class which was responsible for 3 actions: updating the board, tracking the game's status, and display. In order to fix this violation, two additional classes were created, the Display class and the Board class. The Game class now only has the responsibility of tracking the game's status while the Display class prints the chess board and combat interactions and the Board class keeps track of the pieces' locations. This made the code significantly more organized. Along with this violation, there was also a violation of the dependency inversion principle as there was no class for user interactions as it was planned that main would handle this. This would result in the main (a high level module) interacting with the low level modules like Board and Piece. To fix this a UI class was added to communicate with the user. This ensures that the main function at the end of this project will be much cleaner than before.

### Testing Procedure
Our tests mainly used the google test suite. We started by testing the smaller classes, such as the pieces, and then moving up in scale to the display, board, and game, and ending with 
 integration tests held by UI. Since UI is heavily depenendent on user input because it acts as a user interface, all of the user inputs are simulated with text files that hold commands.  
 The unit tests would read through those text files to get input for the tests. We also utilized gcov and lcov to get understandings of what our code was missing during the unit tests. In 
 between, we used Valgrind to locate memory errors and check that the program has no memory leaks, or memcheck--clean. As a final check, we ran a .yml workflow that will run the program through tests during pushes. The .yml workflow will trigger whenever there is a push or pull from main. 
