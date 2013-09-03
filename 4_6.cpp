#include <stdio.h>
#include <vector>

using namespace std;


#define N 20
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)


struct BinaryTreeNode // a node in the binary tree
{
	int value;
	BinaryTreeNode *left; // left child of node
	BinaryTreeNode *right; // right child of node
	BinaryTreeNode *parent;
};



BinaryTreeNode* insert(BinaryTreeNode* root, int val)
{
	if(root)
	{
		if(val < root->value)
		{
			BinaryTreeNode* node = insert(root->left, val);
			root->left = node;
			root->left->parent = root;
		}
		else
		{
			BinaryTreeNode* node = insert(root->right, val);
			root->right = node;
			root->right->parent = root;
		}
			
		return root;
	}
	else
	{
		root = new BinaryTreeNode();
		root->value = val;
		root->left = 0;
		root->right = 0;
		root->parent = 0;
		return root;
	}
}


BinaryTreeNode *search(BinaryTreeNode *root, int val)
{
	if(root)
	{
		if(root->value == val)
			return root;
		BinaryTreeNode *np1 = search(root->left, val);
		if(np1)
			return np1;
		BinaryTreeNode *np2 = search(root->right, val);
		return np2;
	}
	else
	{
		return 0;
	}
}

void printTree(BinaryTreeNode *root, int tab, char c)
{
	if(root)
	{
		printTree(root->left, tab+1, '/');
		for (int i = 0; i < tab; ++i)
			printf("    ");
		printf("%c%d\n", c, root->value);
		printTree(root->right, tab+1, '\\');
	}
}

bool found = false;
BinaryTreeNode *p;
BinaryTreeNode *q;
BinaryTreeNode *f1, *f2;
BinaryTreeNode *ancestor;
void nearestFather(BinaryTreeNode *root, BinaryTreeNode *father)
{
	if(root && !found)
	{
		nearestFather(root->left, root);
		nearestFather(root->right, root);
		if(root == f1)
			f1 = father;
		else if(root == f2)
			f2 = father;
		if(f1 == f2)
		{
			ancestor = f1;
			found = true;
		}	
	}
}



BinaryTreeNode *createOrderTree(int *a, int n)
{
	BinaryTreeNode *root = 0;
	for (int i = 0; i < n; ++i)
	{
		root = insert(root, a[i]);
	}
	return root;
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
	int a[] = {3, 1, 2, 0, 4, 6, 8, 5, 7};
	BinaryTreeNode *root = createOrderTree(a, 9);
	printTree(root, 0, '\0');
	BinaryTreeNode *p  = search(root, 6);
	BinaryTreeNode *q  = search(root, 4);
	f1 = p;
	f2 = q;
	nearestFather(root, 0);
	printf("ancestor: %d\n", ancestor->value);
	destoyTree(root);
	return 0;
}