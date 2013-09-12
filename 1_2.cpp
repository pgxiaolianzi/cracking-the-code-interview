/*
  Write code to reverse a C-Style String. 
  (C-String means that “abcd” is represented as five characters, including the null character.) 
*/


#include <stdio.h>

#define N 500


void reverse(char *s)
{
  int k = 0;
  while (s[k] != '\0')
  {
    k++;
  }
  k--;

  int j = 0;
  while(j < k)
  {
    char t = s[j];
    s[j] = s[k];
    s[k] = t;
    j++;
    k--;
  }

}


int main()
{
  char s[N] = "pgxiaolianzi!";
  printf("former: %s\n", s);
  reverse(s);
  printf("reverse later: %s\n", s);
  return 0;
}
