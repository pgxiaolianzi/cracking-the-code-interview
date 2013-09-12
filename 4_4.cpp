/*
	Given a binary search tree, 
	design an algorithm which creates a linked list of all the nodes at each depth 
	(i.e., if you have a tree with depth D, you’ll have D linked lists). 
*/


#include <stdio.h>
#include <vector>

using namespace std;


#define N 20
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)


struct BinaryTreeNode // a node in the binary tree
{
	int id;
	BinaryTreeNode *left; // left child of node
	BinaryTreeNode *right; // right child of node
};

struct Node
{
	BinaryTreeNode *value;
	Node* next;
};

vector<Node*> heads;

// void insert()
// {

// }

// BinaryTreeNode *createOrderTree(int *a, int n)
// {
// 	for (int i = 0; i < n; ++i)
// 	{
// 		insert()
// 	}
// }

BinaryTreeNode *createMinimalTree(int *a, int s, int d)
{
	if(s <= d)
	{
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

void getDepth(BinaryTreeNode *root, int depth)
{
	if(root)
	{
		Node* newnode = new Node();
		newnode->value = root;
		if(heads.size() < depth+1)
		{
			newnode->next = 0;
			heads.push_back(newnode);
		}
		else
		{
			newnode->next  = heads[depth]->next;
			heads[depth]->next = newnode;
		}	
		getDepth(root->left, depth+1);
		getDepth(root->right, depth+1);
	}
	
}


void destroyLinklist(Node *head)
{
	Node *p = head->next;
	Node *q;
	delete head;
	head = 0;
	while(p)
	{
		q = p->next;
		delete p;
		p = 0;
		p = q;
	}
}


void printLinklist(Node *head)
{
	Node *p = head;
	while(p)
	{
		printf("%d --> ", p->value->id);
		p = p->next;
	}
	printf("null\n");
}

void createLinklistOctave(BinaryTreeNode *root)
{
	if(!root)
		return;	
	getDepth(root, 0);

	vector<Node*>::iterator it = heads.begin();
	while(it != heads.end())
	{
		printLinklist(*it);
		destroyLinklist(*it);
		it++;
	}



	// visit(root->left)
	// queue<BinaryTreeNode *> qe;
	// qe.push(root);
	// while(!qe.empty())
	// {
	// 	BinaryTreeNode *nod = qe.pop();

	// }
	//return heads;
}




int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	BinaryTreeNode *root = createMinimalTree(a, 0, 8);
	printTree(root, 0, '\0');
	createLinklistOctave(root);
	destoyTree(root);
	return 0;
}