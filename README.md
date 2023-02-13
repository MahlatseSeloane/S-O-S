<h1>S-O-S</h1>
<p>For the project, using the IDE CodeBlocks, we were required to develop a computer program in C++ that facilitated the game of S-O-S between two different algorithms. The program was to read a number of board sizes of n × n where 3 ≤ n from a file named input.txt, and facilitate the game for each board size between the two algorithms and record the games in an output file</p>

<p>SOS is a game that requires a minimum of two players to participate. The game begins on an empty square board with the dimensions of at least 3 x 3. Each player takes a turn to place either an "S" or "O" anywhere on the board. The objective is to create a sequence of S-O-S on the board, either horizontally, vertically and diagonally. A player scores points by completing the sequence. If the player succeeds, they are given anotherturn to place a letter until they the player is unable to further create S-O-S, in which the turn is passed to the other player. The game ends when neither players can place any more letters onto the board and the winning player is decided based on the player with the highest score.</p>

<h2>Code Requirements</h2>
<p>The requirements for the project were as follows:

- The should be no input prompt or output on the console.
-	No global variables may be used as this would result in immediate failure.
- Use of at least one Class.
- Use of a Function.
-	Reading in and writing to files.
</p>                       

<h2>Input format</h2>
<p>The input file would contain a list of board sizes that would be used to test the two algorithms against each other. The input file had the following format</p>

PUT PICTURE HERE

<h2>Output format</h2>
<p>The program must produce an output file named results.txt. This file must contain the following:

- size of the board for the current game,
- The move made by each player, along with the player that made the corresponding move,
- The winner of the game.
The history for each board size listed in the input file must be appended to this file with one empty line inbetween different games.

Below is an exapmle of the output file for the games of the boardsizes in the input file:
</p>

PUT PICTURE HERE
<p>Note that coordinates on the board are labelled using the value of the row (r) and column (c) where the top left position is r0c0 and bottom right is r5c5 for a board of size 4 x 4.</p>

Below is the graphical representation of the game play.
