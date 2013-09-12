/*
	Write a program to sort a stack in ascending order. 
	You should not make any assump- tions about how the stack is implemented. 
	The following are the only functions that should be used to write this program: 
	push | pop | peek | isEmpty. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

#define StackCapcity 50


typedef struct Stack
{
	int top;
	int value[StackCapcity];

	Stack();
	void push(int val);
	int pop();
	int peek();
	bool isEmpty();
}Stack;

Stack::Stack()
{
	top = 0;
}


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

int Stack::peek()
{
	if(top <= 0)
	{
		printf("Stack is empty!\n");
		return 0;
	}
	int e = value[top-1];
	return e;
}

bool Stack::isEmpty()
{
	if(top <= 0)
		return true;
	return false;
}

//move stack s1 to s2
void move(Stack& s1, Stack& s2)
{
	while(!s1.isEmpty())
	{
		int te = s1.pop();
		s2.push(te);
		printf("%d ", te);
	}
	printf("\n");
}

void sort(Stack& s)
{
	Stack store;
	Stack back;
	while(!s.isEmpty())
	{
		int e = s.pop();
		if(store.isEmpty())
			store.push(e);
		else
		{
			while(!store.isEmpty() && store.peek() > e)
				back.push(store.pop());
			store.push(e);
			while(!back.isEmpty())
				store.push(back.pop());
		}
	}
	move(store, s);
}


int main()
{
	int a[9] = {3, 4, 5, 2, 6, 8, 1, 1, 4};
	Stack s;
	for (int i = 0; i < 9; ++i)
		s.push(a[i]);
	sort(s);
	while(!s.isEmpty())
		printf("%d ", s.pop());
	printf("\n");
	return 0;
}