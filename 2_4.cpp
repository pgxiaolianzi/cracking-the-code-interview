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

Node *addLinklist(Node *head1, Node* head2)
{
	Node *head3 = new Node();
	Node *tail = head3;
	Node *p, *q, *r;
	p = head1->next;
	q = head2->next;
	int sum;
	int bits;

	while(p && q)
	{
		Node *newnode = new Node();
		sum = p->value + q->value + bits;
		newnode->value = sum%10;
		bits = sum/10;
		tail->next = newnode;
		tail = newnode;

		p = p->next;
		q = q->next;
	}

	while(p)
	{
		Node *newnode = new Node();
		sum = p->value + bits;
		newnode->value = sum%10;
		bits = sum/10;

		tail->next = newnode;
		tail = newnode;
		p = p->next;
	}

	while(q)
	{
		Node *newnode = new Node();
		sum = q->value + bits;
		newnode->value = sum%10;
		bits = sum/10;

		tail->next = newnode;
		tail = newnode;
		q = q->next;
	}

	tail->next = 0;
	return head3;
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
	int a[3] = {3, 1, 5};
	int b[4] = {5, 9, 2, 7};
	Node *head1 = createLinklist(a, 3);
	Node *head2 = createLinklist(b, 4);
	printLinklist(head1);
	printLinklist(head2);
	Node *head3 = addLinklist(head1, head2);
	printLinklist(head3);
	destroyLinklist(head1);
	destroyLinklist(head2);
	destroyLinklist(head3);
	return 0;
}