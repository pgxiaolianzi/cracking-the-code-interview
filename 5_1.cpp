#include <stdio.h>
#include <vector>

using namespace std;


#define N 20
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)


void setBit(int&n, int m, int i, int j)
{
	
	int highPart = n >> j;
	int tt = n - (highPart << j);

	int midPart = tt >> i;	
	int lowPart = tt - (midPart << i);
	// printf(" %d %d %d %d\n", n , highPart, midPart, lowPart);

	midPart = m;
	n = (highPart << j) + (midPart << i) + lowPart;
}


int main()
{
	int n = 236;
	int m = 15;
	setBit(n, m, 1, 4);
	printf("%d\n", n);
	return 0;
}