/* hanoi.c Towers of hanoi
✓ TO DO: Extend the programm such that it creates a graphical output of the disks on the three rods
        introduce a function display(), which is called from hanoi()
        Use global or static variables to keep the status of the disk towers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // for Sleep function
#define MAX_DISKS 100

int game[3][MAX_DISKS]; // 1.rod = start, 2.rod = goal, 3.rod = helper
int disk_size;

void display() {
   printf("Rod 1\t\tRod 2\t\tRod 3\n");
   for (int i =0; i < disk_size; i++) {
      for (int j = 0; j < 3; j++) {
         if (game[j][i] == 0) {
            printf("|");
         } else {
            for (int k = 0; k < game[j][i]; k++) {
               printf("*");
            }
         }
         printf("\t\t");
      }
      printf("\n");
   }
   printf("\n\n\n");
}

void display_center() {
   int max_width = disk_size * 2 - 1;
   for (int i = 0; i < disk_size; i++) {
      for (int j = 0; j < 3; j++) {
         if (game[j][i] != 0) {
            int num_stars = game[j][i] * 2 - 1;
            int padding = (max_width - num_stars) / 2;
            printf("%*s", padding, "");
            for (int k = 0; k < num_stars; k++) {
               printf("*");
            }
            printf("%*s", padding, "");
         } else {
            printf("%*s", max_width, "");
         }
         printf("\t\t");
      }
      printf("\n");
   }
   printf("\n\n\n");
}

void move(int from, int to) {
   for (int i = 0; i < disk_size; i++) {
      if (game[from - 1][i] != 0) {
         int disk = game[from - 1][i];
         game[from - 1][i] = 0;
         for (int j = disk_size - 1; j >= 0; j--) {
            if (game[to - 1][j] == 0) {
               game[to - 1][j] = disk;
               break;
            }
         }
         break;
      }
   }
   display_center();
}

void hanoi(int n, int start, int goal, int helper){
   if(n>0) {
      hanoi(n-1,start,helper,goal);
      move(start, goal);
      hanoi(n-1,helper,goal,start);
   }
}

int main(){
   printf("How many disks?");

   scanf("%d", &disk_size);

   if (disk_size>MAX_DISKS) {
      printf("Too many disks\n");
      return -1;
   }
   for (int i = 0; i < disk_size; i++) {
      game[0][i] = i + 1;
      game[1][i] = 0;
      game[2][i] = 0;
   }

   display();

   hanoi(disk_size, 1, 2, 3);

}