/*
	Implement an algorithm to delete a node in the middle of a single linked list, 
	given only access to that node.
	 EXAMPLE Input: the node ‘c’ from the linked list a->b->c->d->e Result: nothing is returned, 
	but the new linked list looks like a->b->d->e 

*/


#include <stdio.h>
#include <set>

using namespace std;

#define N 500



typedef struct Node
{
	int value;
	Node *next;
}Node;


Node *head = 0;



//insert from tail
void createLinklist(int *a, int n)
{
	head = new Node();
	head->next = 0;
	Node* tail = head;

	for (int i = 0; i < n; ++i)
	{
		Node *newnode = new Node();
		newnode->value = a[i];
		tail->next = newnode;
		tail = newnode;
	}
	tail->next = 0;
}


void deleteNode(int n)
{
	Node *p = head->next;
	int count = n-1;
	while(p && count > 0)
	{
		count--;
		p = p->next;
	}
	//delete node p
	if(!p)
		return;
	else
	{
		Node *q = p->next;
		p->value = q->value;
		p->next = q->next;
		delete q;
		q = 0;
	}
}


void printLinklist()
{
	Node *p = head->next;
	while(p)
	{
		printf("%d --> ", p->value);
		p = p->next;
	}
	printf("null\n");
}

void destroyLinklist()
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


int main()
{
	int a[8] = {1, 3, 4, 5, 2, 3, 5, 5};
	createLinklist(a, 8);
	printLinklist();
	deleteNode(3);
	printLinklist();
	destroyLinklist();
	return 0;
}