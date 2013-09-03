#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;


#define N 32
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)


void intergerRep(int n, int* out)
{
	int k = 0;
	do
	{
		out[k] = n%2;
		k++;
		n /= 2;
	}while(n != 0);

	while(k < N)
	{
		out[k] = 0;
		k++;
	}

	k--;
	while(k >= 0)
	{
		printf("%d", out[k]);
		k--;
	}
	printf("\n");	

}

void swap(int& i, int& j)
{
	int t = i; 
	i = j;
	j = t;
}

int getMinimal(int *s)
{
	int k  = 0;
	while(k < N)
	{
		if(s[k] == 1)
			break;
		k++;
	}
	if(k >= N)
	{
		printf("can't find a getMinimal\n");
		exit(1);
	}

	int onePos = k;
	int zeroPos = k-1;
	printf("%d %d %d\n", onePos, zeroPos, k);
	swap(s[onePos], s[zeroPos]);

	k = 31;
	while(k >= 0)
	{
		printf("%d", s[k]);
		k--;
	}
	printf("\n");
}



int main()
{
	int n = 10;
	int out[32];
	intergerRep(n, out);
	getMinimal(out);
	return 0;
}