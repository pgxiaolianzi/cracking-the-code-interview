/*
	Given a circular linked list, 
	implement an algorithm which returns node at the beginning of the loop. 
	DEFINITION Circular linked list:
	A (corrupt) linked list in which a node’s next pointer points to an earlier node, 
	so as to make a loop in the linked list. 
	EXAMPLE input: A –> B –> C –> D –> E –> C (the same C as earlier) output: C 

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

//insert from tail
Node *createLinklist(int *a, int n)
{
	Node *head = new Node();
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
	return head;
}


void printLinklist(Node *head)
{
	Node *p = head->next;
	while(p)
	{
		printf("%d --> ", p->value);
		p = p->next;
	}
	printf("null\n");
}

Node *loopStart(Node* head)
{
	//construct a loop linklist
	int n = 2;
	Node *p = head->next;
	while(p && n > 0)
	{
		n--;
		p = p->next;
	}
	//
	Node *tail = p;
	while(tail->next)
	{
		tail = tail->next;
	}
	tail->next = p;

	//find start loop
	set<Node *> eles;
	p = head->next;
	while(p)
	{
		if(eles.find(p) != eles.end())
			return p;
		eles.insert(p);
		p = p->next;
	}
	return 0;
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


int main()
{
	int a[5] = {1, 3, 5, 7, 9};
	Node *head = createLinklist(a, 5);
	printLinklist(head);
	Node *start = loopStart(head);
	if(start)
		printf("%x %d\n", start, start->value);
	else
		printf("no loop\n");
	destroyLinklist(head);
	return 0;
}