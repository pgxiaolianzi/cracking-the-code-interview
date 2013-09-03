#include <stdio.h>
#include <string.h>

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

int swapRow(int (*matrix)[4], int t, int m, int cols)
{
	for (int i = 0; i < cols; ++i)
	{
		int temp = matrix[t][i];
		matrix[t][i] = matrix[m][i];
		matrix[m][i] = temp;
	}
}

void rotateMatrix(int (*matrix)[4], int n)
{
	invert(matrix, 4);
	swapRow(matrix, 0, 3, 4);
	swapRow(matrix, 1, 2, 4);
}


int main()
{
	int matrix[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	rotateMatrix(matrix, 4);
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