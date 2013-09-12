/*
  Design an algorithm and write code to remove the duplicate characters 
  in a string without using any additional buffer. 
  NOTE: One or two additional variables are fine. An extra copy of the array is not. 
  FOLLOW UP Write the test cases for this method. 
*/



#include <stdio.h>
#include <string.h>

#define N 500

void removeDuplicate2(char *s)
{
	bool flag[256];
	for (int i = 0; i < 256; ++i)
	{
		flag[i] = false;
	}

	int k = 0;
	while(s[k] != '\0')
	{
		if(flag[s[k]])
		{
			s[k] = '\0';
		}
		flag[s[k]] = true;
		k++;
	}

	int leng = k;
	int p = 0;
	for (int i = 0; i < leng; ++i)
	{
		if(s[i] != '\0')
		{
			s[p] = s[i];
			p++;
		}
	}
	s[p] = '\0';
}

void removeDuplicate(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int p = 0;
    for(int i=0; i < len; ++i)
    {
        if(s[i] != '\0')
        {
            s[p++] = s[i]; //if s[i] = '\0', i++, p keep p
            for(int j=i+1; j < len; ++j)
                if(s[j]==s[i])
                    s[j] = '\0';
            printf("%s\n", s);  
        }
    }
    s[p] = '\0';
}




int main()
{
	char s[N] = "hello world";
	printf("former: %s\n", s);
	removeDuplicate2(s);
	printf("remove later: %s\n", s);
	return 0;
}