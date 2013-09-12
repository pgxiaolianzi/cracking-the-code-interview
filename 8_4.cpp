/*
	Write a method to compute all permutations of a string
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <utility>
#include <map>

using namespace std;


#define N 10
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)

int sums = 0;
int out[N];

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

//no repeat
void permute(char *s, int swapIndex, int end)
{
	// printf("%d %d\n", swapIndex, end);
	if(swapIndex == end)
	{
		sums++;
 		printf("%s\n", s);
		return;
	}

	for (int i = swapIndex; i <= end; ++i)
	{
		swap(s[i], s[swapIndex]);
		permute(s, swapIndex+1, end);
		swap(s[i], s[swapIndex]);
	}
}


void permute2(char *s, int swapIndex, int end)
{
	int notEqual = swapIndex; 
	while(notEqual <= end)
	{
		if(s[notEqual] != s[swapIndex])
			break;
		notEqual++;
	}
	if(notEqual > end)
	{
		sums++;
 		printf("%s\n", s);
		return;
	}

	// printf("%d %d %c %c\n", swapIndex, notEqual, s[swapIndex], s[notEqual]);
	permute2(s, notEqual, end);

	for (int k = swapIndex; k < notEqual; ++k)
	{
		for (int i = notEqual; i <= end; ++i)
		{

			if(s[i] == s[i-1])
				continue;
			// printf("%d %d\n", k, i);
			swap(s[i], s[k]);
			permute2(s, notEqual, end);
			swap(s[i], s[k]);
		}
	}
}


int compare(const void *a, const void *b)
{
	char* a1 = (char*)a;
	char* b1 = (char*)b;
	if(*a1 > *b1)
		return 1;
	else if(*a1 == *b1)
		return 0;
	else
		return -1;
}


//with repeat
void permuteRepate(char *s, int n)
{
	qsort(s, n, sizeof(char), compare);
	printf("sorted: %s\n\n", s);
	permute2(s, 0, n-1);
}


set<char*> stringPermute;
//with repeat
void permuteRepate2(char *s, int swapIndex, int end)
{
	// printf("%d %d\n", swapIndex, end);
	if(swapIndex == end)
	{
		if(stringPermute.find())
		{
			sums++;
 			printf("%s\n", s);
 			char *news = new char[N];
 			memcpy(news, s, N*sizeof(char));
 			stringPermute.push_back(news);
		}
		return;
	}

	for (int i = swapIndex; i <= end; ++i)
	{
		swap(s[i], s[swapIndex]);
		permute(s, swapIndex+1, end);
		swap(s[i], s[swapIndex]);
	}
}


int main()
{
	char s[N] = "hellol";
	int n = strlen(s);
	permuteRepate(s, n);
	// permute(s, 0, n-1);
	printf("sums: %d\n", sums);
	return 0;
}