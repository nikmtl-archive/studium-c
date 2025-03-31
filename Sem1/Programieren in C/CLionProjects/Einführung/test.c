
#include <stdio.h>


int main() {
  for (int i = 0; i < 6; i++) {
    int count = 0;
    for (int j = 0; j < 30; j++) {
      int k = i;
      printf("%d",count %10);
      count++;
      for (; k > 0; k--) {
        printf("-");
        j++;
      }
    }
    printf("\n");
  }
}