/*
  Assume you have a method isSubstring which checks 
  if one word is a substring of another. 
  Given two strings, s1 and s2, 
  write code to check if s2 is a rotation of s1 using only one call to isSubstring 
  (i.e., “waterbottle” is a rotation of “erbottlewat”).  
*/


#include <stdio.h>
#include <string.h>

#define N 500

bool isSubstring(char *subs, char *s)
{

}

bool sameCharacter(char *s1, char *s2)
{
	int flag[256] = {0};

	int k = 0;
	while(s1[k] != '\0')
	{
		flag[s1[k]]++;
		k++;
	}

	k = 0;
	while(s2[k] != '\0')
	{
		flag[s2[k]]--;
		k++;
	}

	for (int i = 0; i < 256; ++i)
	{
		if(flag[i] != 0)
			return false;
	}
	return true;
}

bool isRotate(char *s1, char *s2)
{
	if(!sameCharacter(s1, s2))
		return false;
	char s[N] = s1 + s1;
	if(isSubstring(s2, s))
		return true;
	return false;
}


int main()
{
	char s1[N] = "waterbottle";
	char s2[N] = "erbottlewat";
	bool result = isRotate(s1, s2);
	if(result)
		printf("true;\n");
	else
		printf("false;\n");
	return 0;
}