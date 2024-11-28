// Switch case: Order your burger...
// TO DO 1: Replace the if-statements with switch case and add a default case for invalid input
// TO DO 2: Add support for extra-large and fish burgers
// TO DO 3: Extend the program such that is executed in a loop, which can be aborted by entering 'q' as size
// TO DO 4: If there is a much longer list of options: How can long if-else-chains / switch-case-statements be avoided? //Use function pointers to handle different cases.
// TO DO 5: Optional: Any further ideas for additional sizes and options?

#include <stdio.h>


int main() {
    char size, specials;
    int height;
    float price;

    do{
        printf("Which size you want your burger (s=small, m=medium, l=large, x=extra-large)?");
        scanf(" %c", &size);
        if (size == 'q') return 0;
        printf("Any specials (r=regular: beef, v=veggie, c=cheese, f=fish)?");
        scanf(" %c", &specials);

        switch (size) {
            case 's':
                height = 1;
                price = 2.5f;
                break;
            case 'm':
                height = 2;
                price = 3.5f;
                break;
            case 'l':
                height = 4;
                price = 5.9f;
                break;
            case 'x':
                height = 5;
                price = 7.0f;
                break;
            default:
                printf("Invalid size input.\n");
                return 1;
        }

        printf("\n\n.-\"\"\"\"-.\n");
        while (height--) {
            if (specials == 'c') printf(" ------ \n");
            if (specials == 'v') printf("(xxxxxx)\n");
            else if (specials == 'f') printf(" ~~~~~~ \n");
            else printf("(mmmmmm)\n");
        }
        printf("\\______/\n");
        printf("\n\n%.2f Euro - Enjoy!", price);
        printf("\n\n\n");
    }while (1);


    return 0;
}
