/*
	In the classic problem of the Towers of Hanoi, 
	you have 3 rods and N disks of different sizes which can slide onto any tower. 
	The puzzle starts with disks sorted in ascending order of size from top to bottom
	 (e.g., each disk sits on top of an even larger one). 
	 You have the following constraints: (A) Only one disk can be moved at a time. 
	 (B) A disk is slid off the top of one rod onto the next rod. 
	 © A disk can only be placed on top of a larger disk.
	 Write a program to move the disks from the first rod to the last using Stacks. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

#define StackCapcity 5


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
	{
		push(a[i]);
		//printf("%d %d\n", a[i], minEle(s));
	}
}


typedef struct SetofStacks
{
	Stack* stacks;
	int num;
	int cur;

	void init(int num);
	void push(int val);
	int pop();
	int popAt(int whichStack);
}SetofStacks;


void SetofStacks::init(int num)
{
	this->num = num;
	stacks = new Stack[num];
	cur = 0;
	for (int i = 0; i < num; ++i)
		stacks[i].init();
}

void SetofStacks::push(int val)
{
	if(stacks[cur].top >= StackCapcity)
	{
		cur++;
	}
	if(cur >= num)
	{
		printf("all the stack is full!\n");
		exit(1);
	}
	stacks[cur].push(val);
}

int SetofStacks::pop()
{
	while(cur >= 0 && stacks[cur].top <= 0)
		cur--;
	if(cur < 0)
	{
		printf("no elements in stacks!\n");
		exit(1);
	}
	return stacks[cur].pop();
}

int SetofStacks::popAt(int whichStack)
{
	if(stacks[whichStack].top <= 0)
	{
		printf("no elements in %d stacks!\n", whichStack
			);
		exit(1);
	}
	return stacks[whichStack].pop();
}



int main()
{
	int a[9] = {3, 4, 5, 2, 6, 8, 1, 1, 4};
	SetofStacks ss;
	ss.init(5);
	for (int i = 0; i < 9; ++i)
		ss.push(a[i]);
	int e = ss.pop();
	printf("e: %d\n", e);
	e = ss.popAt(0);
	printf("e: %d\n", e);
	return 0;
}