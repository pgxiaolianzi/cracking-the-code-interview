/*
	Given a directed graph, 
	design an algorithm to find out whether there is a route between two nodes. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 250
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)


struct Graph // a node in the binary tree
{
	int edge[N][N];
	int w[N];
	int nodes;

	void create(int nodeNumber, int *vw, int *ew);
};

void Graph::create(int nodeNumber, int *vw, int *ew)
{
	nodes = nodeNumber;
	for (int i = 0; i < nodes; ++i)
		w[i] = vw[i];
	for (int i = 0; i < nodes; ++i)
	{
		for (int j = 0; j < nodes; ++j)
			edge[i][j] = ew[nodes*i + j];
	}
}

bool DFS(Graph g, int vetex, int* visited, int dest)
{
	visited[vetex] = true;
	// printf("%d\n", vetex);
	for (int i = 0; i < g.nodes; ++i)
	{
		if(g.edge[vetex][i] > 0 && !visited[i])
		{
			if(dest == i)
			{
				//printf("true!\n");
				return true;
			}
				
			int ret = DFS(g, i, visited, dest);
			if(ret)
			{
				// printf("true!\n");
				return true;
			}
		}	
	}
	return false;
}


bool isConnected(Graph g, int src, int dest)
{
	int visited[N];
	for (int i = 0; i < g.nodes; ++i)
		visited[i] = false;
	return DFS(g, src, visited, dest);
}


int main()
{
	Graph g;
	int w[5] = {1, 1, 1, 1 ,1};
	int ew[25];
	srand(time(0));
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if(i == j)
			{
				ew[i*5+j] = 1;
				printf("1 ");
				continue;
			}
			int nu = rand()%100;
			if(nu >50)
				ew[i*5+j] = 1;
			else
				ew[i*5+j] = -1;
			printf("%d ", ew[i*5+j]);
		}
		printf("\n");
	}
	g.create(5, w, ew);

	int src = 1;
	int dest = 3;
	bool ret = isConnected(g, src, dest);
	if(ret)
		printf("connected!\n");
	else
		printf("not connected!\n");
	return 0;
}