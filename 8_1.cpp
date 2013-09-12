
/*
	Write a method to generate the nth Fibonacci number.
*/
	

#include <stdio.h>

using namespace std;


#define N 100
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)

int Fib[N];

int fibbi(int n)
{
	if(n == 0 || n == 1)
	{
		Fib[n] = 1;
		return 1;
	}
	if(Fib[n] != 0)
		return Fib[n];
	int f = fibbi(n-2) + fibbi(n-1);
	Fib[n] = f;
	return f;
}

int main()
{
	for (int i = 0; i < N; ++i)
		Fib[i] = 0;
	printf("%d\n", fibbi(10));
	printf("%d\n", fibbi(8));
	printf("%d\n", fibbi(13));
	return 0;
}