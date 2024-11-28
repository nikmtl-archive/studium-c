/* Shuffles a string */
// TO DO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// TO DO 2: Extend the program such that the first characters of names are not shuffled 
//          (a name may consist of several parts separated by spaces).
// TO DO 3: Extend the program such that two names can be entered and shuffling happens between these two 
// TO DO 4: How can a user make the program crash? What could be done against that problem?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(){
   char name[100], c;
   int i, p1, p2;

   printf("Please enter your name:\n");
   scanf("%99[^\n]", name);
   // Safer alternatives, with some issues -> lecture:
   // scanf("%99[^\n]", name);
   // fgets(name, 100, stdin);  // Read max. 99 chars + space for 0-byte
   
   for(i=0; i<10; i++) 
   {	   
      do {
         p1 = rand() % strlen(name);
      } while (name[p1] == ' ' || p1 == 0 || name[p1-1] == ' ');

      do {
         p2 = rand() % strlen(name);
      } while (name[p2] == ' ' || p2 == 0 || name[p2-1] == ' ');

      c = name[p1];
      name[p1] = name[p2];
      name[p2] = c;

      printf("Hello %s\n", name);
   }
}
*/

//task3

int main() {
   char name1[50], name2[50], combined[101], c;
   int i, p1, p2, len;

   printf("Please enter the first name:\n");
   scanf("%49[^\n]", name1);
   printf("Please enter the second name:\n");
   scanf("%49[^\n]", name2);

   // Combine the two names with a space in between
   snprintf(combined, sizeof(combined), "%s %s", name1, name2);
   len = strlen(combined);

   for (i = 0; i < 10; i++) {
      do {
         p1 = rand() % len;
      } while (combined[p1] == ' ' || p1 == 0 || combined[p1-1] == ' ');

      do {
         p2 = rand() % len;
      } while (combined[p2] == ' ' || p2 == 0 || combined[p2-1] == ' ');

      c = combined[p1];
      combined[p1] = combined[p2];
      combined[p2] = c;

      printf("Hello %s\n", combined);
   }

   return 0;
}
