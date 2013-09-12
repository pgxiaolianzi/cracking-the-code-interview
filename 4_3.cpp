/*
	Given a sorted (increasing order) array, 
	write an algorithm to create a binary tree with minimal height. 
*/


#include <stdio.h>

#define N 20
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)


struct BinaryTreeNode // a node in the binary tree
{
	int id;
	BinaryTreeNode *left; // left child of node
	BinaryTreeNode *right; // right child of node
};


BinaryTreeNode *createMinimalTree(int *a, int s, int d)
{
	if(s <= d)
	{
		printf("tag\n");
		BinaryTreeNode *root = new BinaryTreeNode();
		int mid = (d+s)/2;
		root->id = a[mid];
		BinaryTreeNode *left = createMinimalTree(a, s, mid-1);
		BinaryTreeNode *right = createMinimalTree(a, mid+1, d);
		root->left = left;
		root->right = right;
		return root;
	}
	return 0;
}

void printTree(BinaryTreeNode *root, int tab, char c)
{
	if(root)
	{
		printTree(root->left, tab+1, '+');
		for (int i = 0; i < tab; ++i)
			printf("    ");
		printf("%c%d\n", c, root->id);
		printTree(root->right, tab+1, '-');
	}
}


void destoyTree(BinaryTreeNode *root)
{
	if(root)
	{
		destoyTree(root->left);
		destoyTree(root->right);
		delete root;
	}
}

int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	BinaryTreeNode *root = createMinimalTree(a, 0, 8);
	printf("tag\n");
	printTree(root, 0, '\0');
	destoyTree(root);
	return 0;
}