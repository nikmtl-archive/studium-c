/* Malloc_eratosthenes.c

✓  TO DO 1: Change the Eratosthenes program such that 'max' is a variable and can be entered by the user.
            Use malloc and pointers to allocate the memory for is_prime depending on max.
            Do not forget to use 'free' to free the memory afterwards.
✓  TO DO 2: What happens if you don't use free and if you allocate the memory several times, e.g.
            by putting the whole content of the main function in a loop? 
            - How long can you allocate memory?                                          Answer: The memory is allocated until the program crashes.
            - print the addresses where the memory is allocated.
            - Have a look at the task manager and monitor the memory usage of your program (process).
~  TO DO 3: Have a look at your 'game of life' program:
            - What needs to be done to set the cell array flexibly using malloc?
                Answer: The cell array needs to be set flexibly using malloc by using a pointer to a pointer.
            - How to deal with two-dimensional arrays?
                Answer: Two-dimensional arrays can be dealt with by using ptr=melloc(rows*colums*sizeof(data_type)). Refer to it by using ptr[i+j*sizeof(data_type)].

*/

#include <stdio.h>
#include <stdlib.h>


int main() {
    while (1) {
        int max = 0;
        printf("Enter the maximum number: ");
        scanf("%d", &max);
        int *ptr = malloc(max * sizeof(int));
        if (ptr == NULL) {
            printf("Memory not allocated.\n");
            return -1;
        }

        int i, j;
        /* Initialize Array */
        for (i = 0; i < max; i++)
            ptr[i] = 1;

        for (i = 2; i < max; ++i)
            for (j = 2 * i; j < max; j = j + i)
                ptr[j] = 0;

        printf("Prime numbers are: ");
        for (i = 2; i < max; i++)
            if (ptr[i] > 0)
                printf("%d ", i);

        //Address of the allocated memory
        printf("\nAddress of the allocated memory: %p\n", ptr);
        free(ptr);
        printf("\n Press enter to continue...");
        getchar(); // remove input buffer
        getchar(); // wait for user enter
    }
}
