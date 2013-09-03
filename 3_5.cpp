#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

#define StackCapcity 50


typedef struct Stack
{
	int top;
	int value[StackCapcity];

	void init();
	void createStack(int *a, int n);
	void push(int val);
	int pop();
}Stack;

void Stack::push(int val)
{
	if(top >= StackCapcity)
	{
		printf("overflow!\n");
		return;
	}
	value[top] = val;
	top++;
}


int Stack::pop()
{
	if(top <= 0)
	{
		printf("Stack is empty!\n");
		return 0;
	}

	top--;
	int e = value[top];
	return e;
}

void Stack::init()
{
	top = 0;
}

void Stack::createStack(int *a, int n)
{
	for (int i = 0; i < 9; ++i)
		push(a[i]);
}


typedef struct SelfQueue
{
	Stack s1;
	Stack s2;

	void init();
	void enter(int val);
	int away();
	void enterEfficient(int val);
	int awayEfficient();
}SelfQueue;


void SelfQueue::init()
{
	s1.init();
	s2.init();
}

void SelfQueue::enter(int val)
{
	while(s2.top > 0 && s1.top < StackCapcity)
	{
		int e = s2.pop();
		s1.push(e);
	}
	if(s1.top >= StackCapcity)
	{
		printf("the s1 stack is full!\n");
		exit(1);
	}
	s1.push(val);
}

int SelfQueue::away()
{
	// printf("%d %d\n", s1.top, s2.top);
	while(s1.top > 0 && s2.top < StackCapcity)
	{
		int e = s1.pop();
		s2.push(e);
	}
	// printf("%d %d\n", s1.top, s2.top);
	if(s2.top >= StackCapcity)
	{
		printf("the s1 stack is full!\n");
		exit(1);
	}
	return s2.pop();
}


void SelfQueue::enterEfficient(int val)
{
	if(s1.top < StackCapcity)
		s1.push(val);
	else
	{
		printf("the s1 stack is full!\n");
		exit(1);
	}
}

int SelfQueue::awayEfficient()
{
	if(s2.top <= 0)
	{
		while(s1.top > 0 && s2.top < StackCapcity)
		{
			int e = s1.pop();
			s2.push(e);
		}
	}
	return s2.pop();
}

int main()
{
	int a[9] = {3, 4, 5, 2, 6, 8, 1, 1, 4};
	SelfQueue sq;
	sq.init();
	for (int i = 0; i < 9; ++i)
		sq.enterEfficient(a[i]);
	printf("%d\n", sq.awayEfficient());
	sq.enterEfficient(22);
	sq.enterEfficient(18);
	printf("%d\n", sq.awayEfficient());
	printf("%d\n", sq.awayEfficient());
	return 0;
}