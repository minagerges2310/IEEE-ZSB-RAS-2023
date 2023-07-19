#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *multiply(char *num1, char *num2) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  int *pro = (int *)malloc(sizeof(int) * (len1 + len2));
  memset(pro, 0, sizeof(int) * (len1 + len2));
  for (int i = len1 - 1; i >= 0; i--) {
    for (int j = len2 - 1; j >= 0; j--) {
      int mult = (num1[i] - '0') * (num2[j] - '0');
      int sum = mult + pro[i + j + 1];
      pro[i + j] += sum / 10;
      pro[i + j + 1] = sum % 10;
    }
  }
  char *res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
  int k = 0;
  while (pro[k] == 0 && k < len1 + len2 - 1) {
    k++;
  }
  for (int i = k; i < len1 + len2; i++) {
    res[i - k] = pro[i] + '0';
  }
  res[len1 + len2 - k] = '\0';
  free(pro);
  return res;
}


int main()
{

    char *res = multiply("2", "2");
    printf("%s\n", res);

    free(res); 

    return 0;
}