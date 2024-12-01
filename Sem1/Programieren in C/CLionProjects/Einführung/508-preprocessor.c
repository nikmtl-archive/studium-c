/*
TO DO 1: Use the preprocessor #define directive and modify your previous programs, 
         - e.g. define constants such as maximum values / array sizes, shortcuts for special ascii characters etc.
         - Optionally, try to define macros by using parameters with #define.
         - What problems might occur with such macros (and how can they be solved?):
           example: #define square(x)  x*x
                    result=square(5+3);
                    result=square(++y); 

TO DO 2: Have a look at <stdio.h> and other standard header files and see how preprocessor directives are used there


Preprocessor directives:
# include  	include a source file
# define 	define a macro
# undef 	undefine a macro
# if		  conditional compilation
# ifdef 	conditional compilations
# ifndef 	conditional compilation
# elif 	 	conditional compilation
# else 	 	conditional compilation
# endif 	conditional compilation

*/

/*
Tafel besprechung:
macro:
#define sq(x) x*x
kann schwirichkeiten geben
y=sq(1+2) -> 1+2*1+2 = 5

daher
#define sq(x) (x)*(x)



andere schwierigkeit:
#define db(x) (x)+(x)
2* db(2) -> 2* (2)+(2) = 6

daher
#define db(x) ((x)+(x))


weitere schwierigkeit:
y=1
z=sq(++y)
-> z=++y*++y = 6 oder 9
-> y=3
 */