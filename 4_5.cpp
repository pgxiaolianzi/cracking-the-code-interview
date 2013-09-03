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

//houxu
BinaryTreeNode *successor(BinaryTreeNode *root, BinaryTreeNode *sp)
{
	if(sp->right)
	{
		sp = sp->right;
		while(sp->left)
			sp = sp->left;
		return sp;
	}

	BinaryTreeNode *child = sp;
	sp = sp->parent;
	while(sp && sp->right == child)
	{
		printf("%d\n", sp->value);
		child = sp;
		sp = sp->parent;
	}
	return sp;
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
	BinaryTreeNode *sp  = search(root, 8);
	BinaryTreeNode *fp  = successor(root, sp);
	if(fp)
		printf("successor: %d\n", fp->value);
	else
		printf("no successor!\n");
	destoyTree(root);
	return 0;
}