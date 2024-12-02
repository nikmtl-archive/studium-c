/* command line args
✓ TO DO: Use the command line arguments to modify previous programs from the lecture, e.g.
        devowelizer: provide a string to be "devowelized"
        ascii-art: provide x and y
✓ TO DO: parse the command line arguments: If there is a string "-h" or "-help"
        print a small help text
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int n = 0; n < argc; n++) {
        int is_help = 1;
        char *arg = argv[n];
        char *help1 = "-h";
        char *help2 = "-help";

        // Compare with "-h"
        for (int i = 0; help1[i] != '\0'; i++) {
            if (arg[i] != help1[i]) {
                is_help = 0;
                break;
            }
        }

        // If not "-h", compare with "-help"
        if (!is_help) {
            is_help = 1;
            for (int i = 0; help2[i] != '\0'; i++) {
                if (arg[i] != help2[i]) {
                    is_help = 0;
                    break;
                }
            }
        }

        if (is_help) {
            printf("Usage: program [options]\n");
            printf("Options:\n");
            printf("  -h, -help    Show this help message\n");
            return EXIT_SUCCESS;
        }
    }

    for (int n = 0; n < argc; n++) {
        printf("Command line argument %d is %s\n", n + 1, argv[n]);
    }

    return EXIT_SUCCESS;
}