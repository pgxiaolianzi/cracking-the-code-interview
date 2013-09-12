/*
	Write code to remove duplicates from an unsorted linked list. 
	FOLLOW UP How would you solve this problem if a temporary buffer is not allowed? 

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

void removeDuplicate()
{
	set<int> uniqueset;
	Node *p = head->next;
	Node *pre = head;
	while(p)
	{
		if(uniqueset.find(p->value) != uniqueset.end())
		{
			pre->next = p->next;
			delete p;
			p = 0;
		}
		else
		{
			uniqueset.insert(p->value);
			pre = pre->next;
		}
			
		p = pre->next;
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
	int a[8] = {1, 3, 4, 5, 2, 3, 5, 8};
	createLinklist(a, 8);
	printLinklist();
	removeDuplicate();
	printLinklist();
	return 0;
}