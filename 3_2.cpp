/*
	How would you design a stack which, in addition to push and pop, also has a function min 
	which returns the minimum element? Push, pop and min should all operate in O(1) time. 

*/


#include <stdio.h>
#include <map>

using namespace std;

#define N 500

typedef struct Stack
{
	int top;
	int min;
	int value[N];
	map<int, int> minTr;
}Stack;


void init(Stack& s)
{
	s.top = 0;
	s.min = 1 << 30;
}

void push(Stack& s, int val)
{
	if(s.top >= N)
	{
		printf("overflow!\n");
		return;
	}
	s.value[s.top] = val;
	if(val < s.min)
	{
		s.minTr.insert(pair<int, int>(s.top, val));
		s.min = val;
	}
	s.top++;
}


int pop(Stack& s)
{
	if(s.top <= 0)
	{
		printf("Stack is empty!\n");
		return 0;
	}

	s.top--;
	int e = s.value[s.top];

	if(e == s.min)
	{
		int ind = s.minTr.rbegin()->first;
		if(ind == s.top)
		{
			s.minTr.erase(s.top);
			if(s.minTr.empty())
				s.min = 1 << 30;
			else
				s.min = s.minTr.rbegin()->second;
		}
	}

	return e;
}

int minEle(Stack s)
{
	if(s.top == 0)
	{
		printf("Stack is empty!\n");
		return 0;
	}
	return s.min;
}

void createStack(Stack& s, int *a, int n)
{
	for (int i = 0; i < 9; ++i)
	{
		push(s, a[i]);
		//printf("%d %d\n", a[i], minEle(s));
	}
		
}

void popEmpty(Stack s)
{
	//printf("hello\n");
	while(s.top > 0)
	{
		int e = pop(s);
		printf("%d %d\n", e, s.min);
	}
}



int main()
{
	int a[9] = {3, 4, 5, 2, 6, 8, 1, 1, 4};
	Stack s;
	init(s);
	createStack(s, a, 9);
	popEmpty(s);
	return 0;
}