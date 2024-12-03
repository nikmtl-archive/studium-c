 /* Variables and memory
   have a look the variables in your previous programs, e.g. address_list.c

✓  TO DO 1: Use sizeof to determine how much memory different types require in memory.
✓  TO DO 2: Also consider arrays, structs, enums and unions.
✓  TO DO 3: Use & to determine the addresses of different variables in memory.
✓  TO DO 4: Can you see a difference of addresses for local and global variables?		Answer: Yes, the addresses of global variables are lower than the addresses of local variables. But the addresses of the global variables are not in order.
✓  TO DO 5: How are variables sorted in memory (increasing or decreasing addresses)?     Answer: The addresses of the variables are sorted in decreasing order.
x  TO DO 6: What about addresses of local variables in recursive functions (e.g. hanoi.c)?
✓  TO DO 7: Can you find int variables stored at uneven addresses? How do you judge the result?	Answer: No, the addresses of the variables are stored at even addresses.
✓  TO DO 8: What is the size of the test_struct? Why? Can it be reduced?			Answer: The size of the test_struct is 12 bytes. It can be reduced by 4 bytes by changing the order of the variables.
																							The padding is added because the compiler tries to align the int variables to be at even addresses.
*/

 #include <stdio.h>
//global variables
int global_var1 = 1;
char global_var2 = 'a';
float global_var3 = 1.0;
double global_var4 = 1.0;;


enum test_enum {
	one, two, three
};

struct test_struct {
	char a;  
	int b;
	char c;
	int d;
};

struct test_struct_less_padding {
	int d;
	int b;
	char a;
	char c;
};

union test_union {
    char a;
    int b;
};


int main() {
  	//Arrays
    char arr1[] = "Hello World!";
    char arr2[10];
    char arr3[10][10];
    int arr4[10][10];
    //data structures
    struct test_struct test_struct;
    	test_struct.a = 'a';
    	test_struct.b = 1;
    	test_struct.c = 'b';
    	test_struct.d = 2;
	struct test_struct_less_padding test_struct_less_padding;
		test_struct_less_padding.a = 'a';
		test_struct_less_padding.b = 1;
		test_struct_less_padding.c = 'b';
		test_struct_less_padding.d = 2;
    enum test_enum test_enum = one;
    union test_union test_union = {1};
    //Different variables for address comparison
    int var1 = 1;
    char var2 = 'a';
    float var3 = 1.0;
    double var4 = 1.0;


    // Sizes of different standard types
    printf("----Sizes of different standard types:\n");
	printf("char: %llu byte\n", sizeof(char));				// 1 byte
	printf("int: %llu bytes\n ", sizeof(int));				// 4 bytes
	printf("long: %llu bytes\n", sizeof(long));				// 4 bytes
	printf("short: %llu bytes\n", sizeof(short));				// 2 bytes
    printf("float: %llu bytes\n", sizeof(float));				// 4 bytes
    printf("double: %llu bytes\n", sizeof(double));			// 8 bytes

    // Size of simple data structures
    printf("----Size of simple data structures:\n");
    printf("char array (Hello World!): %llu bytes\n", sizeof(arr1));							// 13 bytes > 12 bytes (Hello World!) + 1 byte (null terminator)
    printf("char array (10 elements): %llu bytes\n", sizeof(arr2));							// 10 bytes
    printf("two-dimensional char array (10x10 elements): %llu bytes\n", sizeof(arr3));		// 100 bytes > 10 bytes * 10 elements
    printf("two-dimensional int array (10x10 elements): %llu bytes\n", sizeof(arr4));			// 400 bytes > 4 bytes * 10 elements * 10 elements
    printf("struct (2 char, 2 int): %llu bytes\n", sizeof(struct test_struct));				// 12 bytes > 1 byte + 3 bytes padding + 4 bytes + 4 bytes
	printf("struct (2 char, 2 int) less padding: %llu bytes\n", sizeof(struct test_struct_less_padding));	// 8 bytes > 4 bytes + 4 bytes
    printf("enum: %llu bytes\n", sizeof(enum test_enum));										// 4 bytes
    printf("union (char/int): %llu bytes\n", sizeof(union test_union));						// 4 bytes > int

	// Addresses of different variables
    printf("----Addresses of different local variables:\n");
    printf("int variable: %p\n", &var1);
    printf("char variable: %p\n", &var2);
    printf("float variable: %p\n", &var3);
    printf("double variable: %p\n", &var4);
    printf("char array (Hello World!): %p\n", &arr1);
    printf("char array (10 elements): %p\n", &arr2);
    printf("two-dimensional char array (10x10 elements): %p\n", &arr3);
    printf("two-dimensional int array (10x10 elements): %p\n", &arr4);
    printf("struct (2 char, 2 int): %p\n", &test_struct);
    printf("enum: %p\n", &test_enum);
    printf("union (int): %p\n", &test_union);

    // Addresses of different global variables
    printf("----Addresses of different global variables:\n");
    printf("int global_var1: %p\n", &global_var1);
    printf("char global_var2: %p\n", &global_var2);
    printf("float global_var3: %p\n", &global_var3);
    printf("double global_var4: %p\n", &global_var4);

	return 0;
}




   

