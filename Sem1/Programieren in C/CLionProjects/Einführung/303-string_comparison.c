/* Compare two strings
✓  TO DO 1: This program does not always give the correct results. What is the problem? Correct it!
✓  TO DO 2: Adapt the comparison such that it can be used for providing an ordering e.g. for phone books
*/

#include <stdio.h>
#include <string.h>

/*
//taks1
int main() {
    char s1[100], s2[100];
    int i, flag;

    printf("Please enter string 1:\n");
    scanf("%99[^\n]", s1);
    if (s1[0] != 0)
        getchar(); // Consume the newline character left by scanf
    printf("Please enter string 2:\n");
    scanf("%99[^\n]", s2);
    if (s2[0] != 0)
        getchar(); // Consume the newline character left by scanf

    //string comparison
    flag = i = 0;


    while (s1[i] || s2[i]) {
        if(s1[i]==0 || s2[i]==0) flag = 1;
        if (s1[i] != s2[i]) {
            flag = 1;
            break;
        }
        i++;
    }


    if (flag)
        printf("Strings are different\n");
    else
        printf("Strings are equal\n");
}
*/


//task2
int main() {
    char s1[100], s2[100];
    int i, result;

    printf("Please enter string 1:\n");
    scanf("%99[^\n]", s1);
    if (s1[0] != 0)
        getchar(); // Consume the newline character left by scanf
    printf("Please enter string 2:\n");
    scanf("%99[^\n]", s2);
    if (s2[0] != 0)
        getchar(); // Consume the newline character left by scanf





    //string comparison
    i = 0;
    while (s1[i] && s2[i]) {
        if (s1[i] < s2[i]) {
            result = -1;
            break;
        } if (s1[i] > s2[i]) {
            result = 1;
            break;
        }
        i++;
    }

    // If both strings are equal up to the length of the shorter one
    if (s1[i] == 0 && s2[i] == 0) {
        result = 0;
    } else if (s1[i] == 0) {
        result = -1;
    } else if (s2[i] == 0) {
        result = 1;
    }

    if (result < 0)
        printf("String 1 comes before String 2\n");
    else if (result > 0)
        printf("String 1 comes after String 2\n");
    else
        printf("Strings are equal\n");

    return 0;
}