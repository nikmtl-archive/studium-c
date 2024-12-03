/* Function_plotter.c
   This program uses pointers to functions, which are passed as arguments in function calls.

✓   TO DO 1: Have a look at the program and see how function pointers are used.
✓   TO DO 2: Extend the draw_function such that the range for x and y can be passed:
			 Define a struct range, which provides values for min, max and step.
    TO DO 3: Extend the draw_function, such that two functions 
             can be passed to the draw function and are shown in the same diagram.
			 Use a NULL pointer to indicate that there is no second function to display.
    TO DO 4: Optional: Add more functions and a menu to flexibly choose
	         which functions to show (use two function pointers).
*/

#include <math.h>
#include <stdio.h>

typedef struct range {
    double min;
    double max;
    double step;
} range;

// Display function
void draw_function(double (*f)(double), range r) {
    double x, y;

    for (y = r.max; y >= r.min; y -= r.step) {
        for (x = r.min; x < r.max; x += r.step) {
            printf("%c", ((*f)(x) >= y && (*f)(x) < y + r.step) ? '*' : ' ');
            // Dereferencing *-operator is optional:
            // f(x) would also work
        }
        printf("\n");
    }
}

// Mathematical function to be displayed
double my_function(double x) {
    return 1.5 * sin(x);
}

int main() {
    double (*fn_ptr)(double); // Defines a variable pointing to a function // double some_function_name(double);
    range r = { -2, 10, 0.5 };
    fn_ptr = &my_function; // & can be omitted
    draw_function(fn_ptr,r); // or directly: draw_function(my_function);
}
