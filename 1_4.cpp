#include <stdio.h>
#include <string.h>

#define N 500

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


int main()
{
	char s1[N] = "abed";
	char s2[N] = "adbc";
	bool result = sameCharacter(s1, s2);
	if(result)
		printf("same!\n");
	else
		printf("different!\n");
	return 0;
}