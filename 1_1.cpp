/*
  Implement an algorithm to determine if a string has all unique characters. 
  What if you can not use additional data structures?
*/

  
#include <stdio.h>

#define N 500

bool unique(char *s)
{
  bool flag[256];
  for (int i = 0; i < 256; ++i)
  {
    flag[i] = false;
  }

  int k = 0;
  while (s[k] != '\0')
  {
    if(flag[s[k]])
    {
      printf("the '%d' repeat in \"%s\"\n", k, s);
      return false;
    }
    flag[s[k]] = true;
    k++;
  }

  return true;
}


int main()
{
  char s[N] = "pgxiaolianzi!";
  bool result = unique(s);
  if(result)  
  {
    printf("no repeat!\n");
  }
  return 0;
}
