 /* Variables and memory
   have a look the variables in your previous programs, e.g. address_list.c

   TO DO 1: Use sizeof to determine how much memory different types require in memory.
   TO DO 2: Also consider arrays, structs, enums and unions.
   TO DO 3: Use & to determine the addresses of different variables in memory.
   TO DO 4: Can you see a difference of addresses for local and global variables?
   TO DO 5: How are variables sorted in memory (increasing or decreasing addresses)?
   TO DO 6: What about addresses of local variables in recursive functions (e.g. hanoi.c)?
   TO DO 7: Can you find int variables stored at uneven addresses? How do you judge the result?
   TO DO 8: What is the size of the following struct? Why? Can it be reduced?
*/

enum test_enum {
	one, two, three
};

struct test {
	char a;  
	int b;
	char c;
	int d;
}; 

struct test my_test;

int main() {
	printf("Size of char: %lu\n", sizeof(char));
	printf("Size of int: %lu\n", sizeof(int));
	printf("Size of struct test: %lu\n", sizeof(struct test));
	printf("Size of my_test: %lu\n", sizeof(my_test));
    printf("Size of enum test_enum: %lu\n", sizeof(enum test_enum));
	return 0;
}




   

