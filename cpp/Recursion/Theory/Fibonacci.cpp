#include <stdio.h>

// fibbonaci -> 0 1 1 2 3 5 8
int fibonacci(int number) {
  if (number==0) return 0;
  if (number==1) return 1;
  else return (fibonacci(number-1) + fibonacci(number-2));
}

int main() {
  int number;
  scanf("%d", &number);

  for (int i = 0; i < number; i++) {
    printf("%d ", fibonacci(i));
  }
  return 0;
}
