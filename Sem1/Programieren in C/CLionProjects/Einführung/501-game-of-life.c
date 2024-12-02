/* Game of life
The "game of life" is an old and very simple approach of simulating evolution 
A 2-dimensional field of cells is regarded with a cell being either empty/dead (0) or occupied/alive (1)
The initial state can be chosen e.g. manually or using some random operations.

The further evolution is governed by the following rules:

Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent. 
At each step in time, the following transitions occur:
   1. Any live cell with fewer than two live neighbours dies, as if by needs to be caused by underpopulation.
   2. Any live cell with more than three live neighbours dies, as if by overcrowding.
   3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
   4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.

The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed � births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.)  The rules continue to be applied repeatedly to create further generations.

see: http://en.wikipedia.org/wiki/Conway's_Game_of_Life


✓ TO DO: Complete the program such that it simulates the game of life.
        Do it as teamwork (e.g. in teams with 2 or 3)
        and benefit from being able to develop functions independently and integrate them into the final program.
  TO DO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states.
  TO DO optional 2: let the program find a start state such that the system stays alive and unstable for as long as possible
✓ TO DO optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
  TO DO optional 4: extend the program such that the content of the cells can be edited by the user.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // for Sleep function

// Global 2-dim-array which contains the cells
char cells[30][50];


//A function to initialize the cells
void initialize_cells(){
   srand(time(NULL)); // Seed the random number generator
   for(int i=0; i<30; i++) {
	   for(int j=0; j<50; j++) {
		   cells[i][j] = (rand() % 20) < 1 ? 1 : 0; // Set approximately 5% of cells to 1 and the rest to 0
	   }
   }
}

//A function to display the cells
void display_cells(){
   char buffer[1550]; // 30 rows * 50 columns + 30*/n + 1*\0
   int index = 0;

   system("CLS"); // sends Clear screen to the console (Windows), Linux: "clear"

   for(int i=0; i<30; i++) {
      for(int j=0; j<50; j++) {
         buffer[index++] = cells[i][j] ? 'X' : ' ';
      }
      buffer[index++] = '\n';
   }
   buffer[index] = '\0'; // Null-terminate the string

   printf("%s", buffer);
}


// Function to count live neighbors
int count_live_neighbors(int x, int y){
   int count = 0;
   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         if (i == 0 && j == 0) continue; // Skip the cell itself
         int nx = x + i;
         int ny = y + j;
         count += cells[(nx%30)][(ny%50)];

      }
   }
   return count;
}
void evolution_step(){
   //1. Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
   //2. Any live cell with more than three live neighbours dies, as if by overcrowding.
   //3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
   //4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.
   char cells_helper[30][50];



   // Calculate the next step
   for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 50; j++) {
         int live_neighbors = count_live_neighbors(i, j);
         if (cells[i][j] == 1) { // Cell is alive
            if (live_neighbors < 2 || live_neighbors > 3) { // Underpopulation or overcrowding
               cells_helper[i][j] = 0; // Dies (1,2)
            } else {
               cells_helper[i][j] = 1; // Lives (3)
            }
         } else { // Cell is dead (4,)
            if (live_neighbors == 3) {
               cells_helper[i][j] = 1; // Becomes alive
            } else {
               cells_helper[i][j] = 0; // Stays dead
            }
         }
      }
   }

   // Copy the helper array back to the original array
   for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 50; j++) {
         cells[i][j] = cells_helper[i][j];
      }
   }
}

/*
// Function to check if the system is stable
int checkStable() {
   static int count= 0;
   static char last_cells_helper[30][50];
   static char nextToLast_cells_helper[30][50];
   count ++;
   if (count < 2) {
      return 0;
   }

   int flag = 0;
   for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 50; j++) {
         nextToLast_cells_helper[i][j] = cells[i][j];
         flag ++;
      }
   }


   for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 50; j++) {
         nextToLast_cells_helper[i][j] = last_cells_helper;
         last_cells_helper[i][j] = cells;
      }
   }

   if (flag == 1500) {
      return 1;
      printf("The system is stable");
   }

   return 0;
}
*/

// Main program
int main(){
   initialize_cells();

   while (1) {
      display_cells();
      evolution_step();

      //wait 1sec
      Sleep(1000);
   }
}