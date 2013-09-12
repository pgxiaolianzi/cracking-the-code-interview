/*
	Implement an algorithm to find the nth to last element of a singly linked list. 
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

//half
Node* lastNthElement(int n)
{
	Node *fast, *slow;
	fast = head->next;
	int flag = n;
	while(fast && flag > 0)
	{
		flag--;
		fast = fast->next;
	}
	if(flag > 0)
		return 0;

	slow = head->next;
	while(fast)
	{
		//printf("%d %d\n", fast->value, slow->value);
		fast = fast -> next;
		slow = slow -> next;
	}
	return slow;
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
	Node *ne = lastNthElement(8);
	if(ne)
		printf("%d\n", ne->value);
	else
		printf("total elements < n !\n");
	destroyLinklist();
	return 0;
}