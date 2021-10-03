#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("What number do you want to search?\n");
  int x;
  scanf("%d", &x);
  int posisi = -1;
  for (int i = 0; i < n; i++) {
    if(arr[i]==x) {
      posisi=i;
      break;
    }
  }

  printf("%d is in index %d\n", x, posisi);

  return 0;
}
