# GameOfLife

The “game of life” is a cellular automaton, consisting of a two-dimensional grid of cells. Each cell is either alive or dead. 
Cells either die, stay alive, or are born using the following rules: 
•	For cells that are alive: 
o	If the cell has 0 or 1 neighbors, it dies from loneliness 
o	If the cell has 2 or 3 neighbors, it lives on to the next round 
o	If the cell has 4 or more neighbors, it dies from overpopulation 
•	For cells that are not alive 
o	If the cell has 3 alive neighbors, a new cell is born in this location 
o	If the cell has either more than 3 or fewer than 3 neighbors, it remains dead 

The game is “played” in generations. An initial setup says which cells are alive. The rules specify which cells will exists in the next generation. All cells “off the gird” (that is, with a row or column out of bounds) are permanently “dead”.

I Create 2D character array of size 20 by 20. A cell holding character ‘\0’ is dead cell and a cell holding character ‘X’ is alive cell. Initially initialize the entire 2D array with ‘\0’ character. Then read of the positions of alive cells from a text file (format is discussed ahead) and set the value of those cells as ‘X’. The state of the matrix after setting alive cells is the first generation of the game. The next state of matrix will be created according to rules above. Each cell of the current generation matrix will be tested to check if it will be dead or alive in next generation matrix.For any given cell it has eight neighboring cells surrounding it.

User Inputs 
Right now this main program is running endlessly.
I must ask user to enter the number of generations he wants to produce for a given matrix. Let us say user enters value 50 then this loop should run no more than 50 time.
The the loop is taking 1 second break before next iteration. You must also let user choose whether he wants to let every next generation display in one second’s span automatically or he wants to go to next generation on a key press. Your program should work accordingly. 

Demo is NOT asking user for any inputs and runs endlessly for file “Life1.txt”, displaying each generation at one second’s difference. 

