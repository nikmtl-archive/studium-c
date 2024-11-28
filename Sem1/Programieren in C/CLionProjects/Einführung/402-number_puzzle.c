/* number_puzzle.c 
   Write a number puzzle program by completing the TO DOs
   TO DO 1: Initialize the puzzle, such that the numbers 1 to 15 are randomly distributed in the array.
            -1 should mark the empty field.
   TO DO 2: get key and move pieces accordingly (if keystroke is valid)
   TO DO 3: Check, if puzzle is in correct order -> set sorted=1
   TO DO 4: Create a more fancy output, e.g. by creating frames around the numbers
                (Use a special character e.g. a block rather than '*')
                (Also, mark the empty field rather than showing -1)

            *********************
            *  1 *  2 *  3 *  4 *
            *********************
            *  5 *  6 *  7 *  8 *
            *********************
            *  9 * 10 * 11 * 12 *
            *********************
            * 13 * 14 * 15 *    *
            *********************

   TO DO 5, optional: created an automatic, intelligent puzzle solver, which solves the puzzle without user interaction.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void initialize_puzzle(int puzzle[4][4]) {
   int numbers[16];
   for (int i = 0; i < 15; i++) {
      numbers[i] = i + 1;
   }
   numbers[15] = -1;


   // Shuffle the numbers array
   srand(time(NULL));
   for (int i = 0; i < 16; i++) {
      int j = rand() % 16;
      int temp = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = temp;
   }

   // Fill the puzzle with shuffled numbers
   int k = 0;
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
         puzzle[i][j] = numbers[k++];
      }
   }
}

void move_piece(int puzzle[4][4], char key) {
   int i, j, empty_i, empty_j;

   // Find the position of the empty field
   for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
         if (puzzle[i][j] == -1) {
            empty_i = i;
            empty_j = j;
            break;
         }
      }
   }

   // Move the empty field based on the key
   switch (key) {
      case 'w': // Move up
         if (empty_i > 0) {
            puzzle[empty_i][empty_j] = puzzle[empty_i - 1][empty_j];
            puzzle[empty_i - 1][empty_j] = -1;
         }
      break;
      case 's': // Move down
         if (empty_i < 3) {
            puzzle[empty_i][empty_j] = puzzle[empty_i + 1][empty_j];
            puzzle[empty_i + 1][empty_j] = -1;
         }
      break;
      case 'a': // Move left
         if (empty_j > 0) {
            puzzle[empty_i][empty_j] = puzzle[empty_i][empty_j - 1];
            puzzle[empty_i][empty_j - 1] = -1;
         }
      break;
      case 'd': // Move right
         if (empty_j < 3) {
            puzzle[empty_i][empty_j] = puzzle[empty_i][empty_j + 1];
            puzzle[empty_i][empty_j + 1] = -1;
         }
      break;
      default:
         printf("Invalid move!\n");
      break;
   }
}

int is_sorted(int puzzle[4][4]) {
   int expected = 1;
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
         if (i == 3 && j == 3) {
            if (puzzle[i][j] != -1) {
               return 0;
            }
         } else {
            if (puzzle[i][j] != expected++) {
               return 0;
            }
         }
      }
   }
   return 1;
}

void print_puzzle(int puzzle[4][4]) {
   printf("---------------------\n");
   for (int i = 0; i < 4; i++) {
      printf("|");
      for (int j = 0; j < 4; j++) {
         if (puzzle[i][j] == -1) {
            printf("    |");
         } else {
            printf(" %2d |", puzzle[i][j]);
         }
      }
      printf("\n---------------------\n");
   }
}

int main()
{
   int puzzle[4][4];
   char key;            // This holds the current key entered by the player.
   char sorted=0;       // This flag indicates whether the field is sorted.  
   int i, j;
   initialize_puzzle(puzzle);

   while(!sorted) {

      print_puzzle(puzzle);
    
      printf("move into direction (w=up, s=down, a=left, d=right) ?");
      key=getch();

      move_piece(puzzle, key);

      if (is_sorted(puzzle)) {
         sorted = 1;
         printf("Puzzle is sorted!\n");
      }
   }
}
