/* devowelizer / revowelizer 
✓  TO DO 1: Extend the program such that it replaces all vowels in the text with other vowels.
✓  TO DO 2: Extend the program such that the replacement vowel is chosen randomly.
          Hint: List the vowels in an additional array ...
                Use rand() to generate random numbers
✓  TO DO 3: Modify the program such that it removes all vowels (and shortens the text accordingly)
 TO DO 4 (optional): Write an encryption/decryption program which encodes texts by defining
         in a table how each character shall be replaced by another one. 
*/

#include <stdio.h>
#include <stdlib.h>

//taks 1&2
/*
int main() {
    char txt[1000];
    char vowels[] = "aeiou";
    int vowels_size = sizeof(vowels)-1;
    int i = 0;

    printf("Please enter your text:");
    scanf("%999[^\n]", txt);

    while (txt[i] != 0) {
        for (int j = 0; j < vowels_size-1; j++) {
            if (txt[i] == vowels[j]) {
                txt[i] = vowels[rand() % vowels_size]; // Replace with a random vowel
                break;
            }
        }
        i++;
    }
    printf("%s", txt);
}
*/

//task 3
int main() {
    char txt[1000];
    char result[1000];
    char vowels[] = "aeiou";
    int vowels_size = sizeof(vowels)-1;
    int counter = 0, is_vowel, i = 0;

    printf("Please enter your text:");
    scanf("%999[^\n]", txt);

    while (txt[i] != 0) {
        is_vowel = 0;
        for (int j = 0; j < 5; j++) {
            if (txt[i] == vowels[j]) {
                is_vowel = 1;
                break;
            }
        }
        if (!is_vowel) {
            result[counter] = txt[i];
            counter++;
        }
        i++;
    }
    result[counter] = '\0'; // Null-terminate the result string
    printf("%s", result);
}