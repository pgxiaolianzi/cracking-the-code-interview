/*
	Write a method that returns all subsets of a set.
*/


#include <stdio.h>
#include <utility>
#include <map>

using namespace std;


#define N 10
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)

int sums = 0;
int e;
int out[N];

//recursion
void subset(int *a, int s, int k)
{
	if(s <= e)
	{
		subset(a, s+1, k);

		out[k] = a[s];
		k++;
		subset(a, s+1, k);
	}
	else
	{
		for (int i = 0; i < k; ++i)
		{
			printf("%d ", out[i]);
		}
		printf("\n");
		sums++;
	}
	
}

//visit n-bit binary, for n is not larger than 32 bits
void subset2(int *a, int n)
{
	int max = 1 << n;
	int binary[32];
	for (int i = 0; i < max; ++i)
	{
		int temp = i;
		int k = 0;
		do
		{
			binary[k] = temp % 2;
			if(binary[k] == 1)
				printf("%d ", a[k]);
			temp /= 2;
			k++;
		}while(temp != 0);
		printf("\n");
		// for (int j = 0; j < 32; ++j)
		// {
		// 	if()
		// }
	}
}


int main()
{
	int a[] = {1, 2, 9, 4, 5, 6, 7, 8};
	int out[N];
	e = 7;
	subset(a, 0, 0);
	subset2(a, 8);
	printf("sums: %d\n", sums);
	return 0;
}