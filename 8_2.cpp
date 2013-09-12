/*
	Imagine a robot sitting on the upper left hand corner of an NxN grid. 
	The robot can only move in two directions: right and down. 
	How many possible paths are there for the robot?
	FOLLOW UP,
	Imagine certain squares are “off limits”, 
	such that the robot can not step on them. 
	Design an algorithm to get all possible paths for the robot.
*/


#include <stdio.h>
#include <utility>
#include <map>

using namespace std;


#define N 10
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)

map< pair<int, int>, int > disp;

bool canMove(int x, int y)
{
	if((x >= 0 && x < N) && (y >= 0 && y < N))
		return true;
	return false;
}

int move(pair<int, int> src, pair<int, int> dest)
{
	int x = src.first;
	int y = src.second;
	if(x == dest.first && y == dest.second)
	{

		return 1;
	}
	if(!canMove(x, y))
		return 0;

	map< pair<int, int>, int >::iterator it;
	it = disp.find(src);
	if(it != disp.end())
		return it->second;

	pair<int, int> step1(x+1, y);
	pair<int, int> step2(x, y+1);
	int s = move(step1, dest) + move(step2, dest);
	disp.insert(pair< pair<int, int>, int >(src, s));
	return s;
}

int main()
{
	pair<int, int> src(0, 0);
	pair<int, int> dest(N-1, N-1);
	int methods = move(src, dest);
	printf("%d\n", methods);
	return 0;
}