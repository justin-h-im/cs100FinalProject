# final-project-mhsie026-jim023-anels048-vselv001

Justin Im
Athena Nelson
Marcus Hsieh
Vimal Selvarajan

CHESS++

Why is it important or interesting to you?
We find that chess is a repeatable and boring game that has not received any meaningful updates in the past 2000 years. We are also bad at chess. 
We will attempt to add new mechanics to a classic game that are reminiscent of turn-based style combat.
We hope to put a twist on chess that will intrigue younger generations of players. 

What languages/tools/technologies do you plan to use?
- C++
- Possibly the SDL library

What will be the input/output of your project?
- Output
  - Menu Select screen.
  - Chess board after each move.
  - List of possible moves for beginners. 
- Input:
  - Location of the piece to be moved.
  - Coordinates of the new location.
  - Prompts for actions for the combat scenario.
  - Attack
    - 2 options
      - Normal attack
      - Each piece has a unique ability
    - Flee


What are the features that the project provides?
- 2-player local multiplayer chess
  - Ascii art to represent the board and pieces
  - Each player gets a turn to choose a piece to move
    - Touch-move chess (once a player touches(selects) a piece they must move or capture if it is legal to do so) 
  - The goal is the same as normal chess, so each player must try to checkmate the other player’s king
- Everytime a player attempts to capture, the two players enter a turn-based combat scenario.
- Each player chooses a combat ability innate to their pieces, and effectiveness of attack is determined by a dice roll.
  - The players will see the result of this dice roll.
  - D20 for accuracy
    - Whether or not the attack will hit is determinant on an RNG mechanic.
    - The players will see a message that displays “hit” or “miss”.
  - D20 for attack
    - Damage is scaled to the piece’s maximum attack. 
- Pawns will be able to change their piece.
  - This will be determined by a D6 roll, with each number representing a possible piece.
  - It will be able to change into any of the existing chess pieces
  - If the pawn rolls to be another pawn, it will move backwards. 

