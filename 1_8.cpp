#include <stdio.h>
#include <string.h>

#define N 500

bool isSubstring(char *subs, char *s)
{
	int k = 0;
	int p = 0;
	int start = 0;
	while(s[k] != '\0')
	{
		start = k+1;
		p = 0;
		while(s[k] != '\0' && subs[p] != '\0' && s[k] == subs[p])
		{
			p++;
			k++;
		}
		if(subs[p] == '\0')
		{
			printf("is sub string !\n");
			return true;
		}
		if(s[k] == '\0')
			return false;
		k = start;
	}
	return false;
}


void getnext(int *next, char *pattern)
{
	int n = strlen(pattern);
	next[0] = 0;
	next[1] = 1;
	for (int i = 0; i <= n; ++i)
	{
		next
	}
}
//KMP
bool isSubstring2(char *subs, char *s)
{
	int next[N] = {0};
	getnext(next, subs);
	int k = 0;
	int p = 0;
	int start = 0;

	while(s[k] != '\0')
	{
		start = k;
		p = 0;
		while(s[k] != '\0' && subs[p] != '\0' && s[k] == subs[p])
		{
			p++;
			k++;
		}
		if(subs[p] == '\0')
		{
			printf("is sub string !\n");
			return true;
		}
		if(s[k] == '\0')
			return false;
		k = start + (p - next[p]);
	}
	return false;
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
	strcat(s1, s1);
	if(isSubstring(s2, s1))
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