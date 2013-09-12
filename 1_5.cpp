/*
  Write a method to replace all spaces in a string with ‘%20’. 
*/


#include <stdio.h>
#include <string.h>

#define N 500


void replace(char *s, char *rs)
{
	int rn = strlen(rs);
	int sn = 0; //space
	int k = 0;
	while(s[k] != '\0')
	{
		if(s[k] == ' ')
			sn++;
		k++;
	}
	k--;
	int n = k;

	int j = n + sn * (rn - 1);
	for (int i = n; i >= 0; --i)
	{
		if(s[i] == ' ')
		{
			for (int t = rn-1; t >= 0; --t)
			{
				s[j] = rs[t];
				j--;
			}
		}
		else
		{
			s[j] = s[i];
			j--;
		}
	}
}


int main()
{
	char s[N] = "hello world yeah";	
	char rs[N] = "%20";
	printf("former: %s\n", s);
	replace(s, rs);
	printf("later: %s\n", s);
	return 0;
}