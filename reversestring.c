#include <stdio.h>
void revstr()
{
  char str[1000];
  int i, j, count = 0;
  scanf("%s", str);
  printf("\nString Before Reverse: %s", str);
  //finding the length of the string
  while (str[count] != '\0')
  {
    count++;
  }
  j = count - 1;

  //reversing the string by swapping
  for (i = 0; i < count/2; i++)
  {
      char ch = str[i];
      str[i] = str[j];
      str[j] = ch;
      j--;
  }

  printf("\nString After Reverse: %s", str);
}