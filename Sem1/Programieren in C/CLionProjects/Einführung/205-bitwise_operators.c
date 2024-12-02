/* bitwise_operators.c binary operations
✓ TO DO 1: Something is wrong with the output Hint: put the output first into an additional variable m, use bitwise operators and count the digits
✓ TO DO 2: A second number should be entered and both numbers should be combined with the various bitwise operators before providing the output
✓ TO DO 3: Use signed integers and see how negative numbers are presented in binary format */

#include <stdio.h>

//task1
/*
int main() {
	unsigned int n, m, size;

	printf("Please enter an integer number:");
	scanf("%u",&n);   // Input unsigned integer from console
    printf("\n Binary representation: ");
	size = n;

	while (n>0) {
		m=m << 1;
		m= m | (n&1);
		n=n >> 1;
	}

	do{
		printf("%d",m&1);
		m=m >> 1;
		size=size >> 1;
	}while (size>0);
}

*/



//task2

void printBinary(unsigned int n) {
	unsigned int m, size;

	size = n;

	while (n) {
		m<<=1;
		m= m | (n&1);
		n>>=1;
	}

	do {
		printf("%d",m&1);
		m>>=1;
		size>>=1;
	}while (size);
	printf("\n");
}

int main() {
	unsigned int n1, n2;

	printf("Please enter the first integer number: ");
	scanf("%u", &n1);
	printf("Please enter the second integer number: ");
	scanf("%u", &n2);

	printf("\nBinary representation of first number: ");
	printBinary(n1);

	printf("Binary representation of second number: ");
	printBinary(n2);

	printf("\nBitwise AND of first and second number: ");
	printBinary(n1 & n2);

	printf("Bitwise OR of first and second number: ");
	printBinary(n1 | n2);

	printf("Bitwise XOR of first and second number: ");
	printBinary(n1 ^ n2);
}
