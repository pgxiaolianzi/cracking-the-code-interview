#include <stdio.h>
#include <set>

using namespace std;

#define N 500


void invert(int (*matrix)[4], int n)
{
	if(n != 4)
	{
		printf("not square matrix\n");
		return;
	}
	//swap
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			int temp = matrix[j][i];
			matrix[j][i] = matrix[i][j];
			matrix[i][j] = temp;
		}
	}
}

void resetzero(int (*matrix)[4], int n)
{
	set<pair<int, int> > zeroRowCols;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(matrix[i][j] == 0)
				zeroRowCols.insert(pair<int, int>(i, j));
		}
	}
	for (set<pair<int, int> >::iterator iter = zeroRowCols.begin(); iter != zeroRowCols.end() ; ++iter)
	{
		int first = iter->first;
		int second = iter->second;
		for (int i = 0; i < 4; ++i)
		{
			matrix[first][i] = 0;
		}
		for (int i = 0; i < n; ++i)
		{
			matrix[i][second] = 0;
		}
	}
}

int swapRow(int (*matrix)[4], int t, int m, int cols)
{
	for (int i = 0; i < cols; ++i)
	{
		int temp = matrix[t][i];
		matrix[t][i] = matrix[m][i];
		matrix[m][i] = temp;
	}
}


int main()
{
	int matrix[4][4] = {
		{1, 2, 3, 4},
		{5, 0, 7, 8},
		{9, 10, 11, 12},
		{13, 0, 15, 16}
	};
	resetzero(matrix, 4);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}