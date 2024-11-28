/* prime sieve of Eratosthenes */
// TO DO 1: The program seems to work, but look carefully at the results -> There is a (typical) bug
// TO DO 2: Extend it such that the maximum number n to be calculated can be entered by the user
//          Use scanf("%d", &n)
// TO DO 3: What does this mean for the array? How should the program be adapted to work reliably? 

#include <stdio.h>

#define MAX 100000

int main(){

   char is_prime[MAX];   // For full compatibility (C89, C90, C11) Array size has to be a constant!
   int i, j;
   
   //initialize the array
   for(i=0; i<MAX; i++)
      is_prime[i]=1;

   //get the maximum number
   int n = 0;
   printf("Enter the maximum number: ");
   scanf("%d", &n);
   if (n >= MAX || n < 1) {
      printf("Number too large\n");
      return 1;
   }


   //find the prime numbers
   for(i=2; i<=n; i++)
      for(j=2*i; j<=n; j=j+i)
         is_prime[j] = 0;


   //print the prime numbers
   printf("Prime numbers are: ");
   for(i=2; i<n; i=i+1)
      if(is_prime[i]>0)
         printf("%d ",i);  
}