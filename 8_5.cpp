/*
	Implement an algorithm to print all valid 
	(e.g., properly opened and closed) combinations of n-pairs of parentheses.
	EXAMPLE:
	input: 3 (e.g., 3 pairs of parentheses)
	output: ((())), (()()), (())(), ()(()), ()()()
*/


#include <stdio.h>
#include <utility>
#include <map>

using namespace std;


#define N 10
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)

int sums = 0;
char out[N];


void permuteParenthese(int n, int needRight, int octave)
{
	// printf("n: %d, needRight: %d, octave: %d\n", n, needRight, octave);

	out[octave] = '(';
	octave++;
	needRight += 1;
	if(n > 1)
	{
		int count = needRight;
		for (int printRight = 0; printRight <= count; ++printRight)
		{
			permuteParenthese(n-1, needRight, octave);
			out[octave] = ')';
			octave++;
			needRight--;
		}
	}
	else
	{
		while(needRight > 0)
		{
			out[octave] = ')';
			octave++;
			needRight--;
		}
		out[octave] = '\0';
		printf("%s\n", out);
		sums++;
	}
}


int main()
{
	int n = 4;
	permuteParenthese(n, 0, 0);
	printf("sums: %d\n", sums);
	return 0;
}