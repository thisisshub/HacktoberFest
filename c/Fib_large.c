#include <stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX 100000

void addStringNumbers(char num1[], char num2[], char final[]){
  int carry = 0;
  for (unsigned int i = MAX - 1; i >= 0; i--){
    int digit = (num1[i] - '0') + (num2[i] - '0') + carry;
    final[i] = (digit % 10) + '0';
    carry = digit / 10;
  }
}

char prev1[MAX];
char prev2[MAX];
char final[MAX];

int main(){
  unsigned int n;
  
  for (unsigned int i = 0; i < MAX; i++){
    prev1[i] = prev2[i] = final[i] = '0';
  }
  prev2[MAX - 1] = '1';


  scanf("%d", &n);

  if (n == 0 || n == 1){
    printf("%c", n + '0');
  }
  else{
    for (unsigned int i = 2; i <= n; i++){
      addStringNumbers(prev1, prev2, final);
      strcpy(prev1, prev2);
      strcpy(prev2, final);
    }

    bool check = false;
    for (unsigned int i = 0; i < MAX; i++){
      if (!check && final[i] == '0')
        continue;

      if (!check && final[i] != '0')
        check = true;
      printf("%c", final[i]);
    }
    printf("\n");
  }
  return 0;
}