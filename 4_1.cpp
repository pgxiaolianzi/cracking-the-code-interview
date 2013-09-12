/*
	Implement a function to check if a tree is balanced. 
	For the purposes of this question, a balanced tree is defined to be a tree 
	such that no two leaf nodes differ in distance from the root by more than one. 
*/


#include <stdio.h>

#define N 20
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)


struct BinaryTreeNode // a node in the binary tree
{
	int id;
	BinaryTreeNode *m_pLeft; // left child of node
	BinaryTreeNode *m_pRight; // right child of node
};

int dist[N][N];
BinaryTreeNode tree[N];
int treeNodes;
int treeRoot;


void createTree(int nodeNumber, int (*array)[3], int n)
{
	treeNodes = nodeNumber;
	for (int i = 0; i < nodeNumber; ++i)
	{
		tree[i].id = i;
	 	tree[i].m_pLeft = 0;
	 	tree[i].m_pRight = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		if(array[i][1] >= 0) //left child
			tree[array[i][0]].m_pLeft = &tree[array[i][1]];
		if(array[i][2] >= 0)
			tree[array[i][0]].m_pRight = &tree[array[i][2]];
	}
}


bool Balance(BinaryTreeNode* root, int& maxdepth)
{
	if(root)
	{
		int dp1, dp2;
		if(!Balance(root->m_pLeft, dp1))
			return false;
		if(!Balance(root->m_pRight, dp2))
			return false;
		int diff = abs(dp1 - dp2);
		if(diff > 1)
			return false;
		maxdepth = max(dp1, dp2) + 1;
		// printf("%s\n", );
		return true;
	}
	else
	{
		maxdepth = 0;
		return true;
	}
}

int main()
{
	// int relation[8][3] = {{0, 1, 2}, {1, 3, 4}, {3, 5, 6}, {4, 7, 8}, {5, 9, 10}, 
	// 						{7, 11, -1}, {9, 12, 13}, {11, 14, -1}};
	int relation[6][3] = {{0, 1, 2}, {1, 3, 4}, {3, 5, 6}, {4, 7, 8}, {5, 9, 10}, 
							{7, 11, -1}};
	// int relation[2][3] = {{0, 1, 2}, {1, 3, 4}};
	createTree(12, relation, 6);
	int depth;
	bool ret = Balance((&tree[treeRoot])->m_pLeft, depth);
	if(ret)
		printf("balance tree!\n");
	else
		printf("not a balance tree!\n");
	return 0;
}