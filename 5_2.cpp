/*
	Given a (decimal – e.g. 3.72) number that is passed in as a string, print the binary representation. 
	If the number can not be represented accurately in binary, print “ERROR” 
*/


#include <stdio.h>
#include <vector>

using namespace std;


#define N 20
#define max(x, y) (x>y? x: y)
#define abs(x) (x > 0? x: -x)


void intergerRep(int n)
{
	char out[N];
	int k = 0;
	do
	{
		out[k] = n%2;
		k++;
		n /= 2;
	}while(n != 0);
	k--;

	while(k >= 0)
	{
		printf("%d", out[k]);
		k--;
	}
		
}

void binaryRepsentation(char *s)
{
	int k = 0;
	bool point = false;
	int intBit = 0;
	int floatBit = 0;
	int num = 0;
	while(s[k] != '\0')
	{
		if(s[k] == '.')
		{
			point = true;
		}
		else
		{
			if(!point)
				intBit++;
			else
			{
				if(intBit == 0 && s[k] == '0')
					floatBit++;
			}	
			num = num * 10 + s[k] - '0';
		}
		k++;
	}

	intergerRep(num);
	//not a integer
	if(point)
	{
		if(intBit > 0)
		{
			printf("*e(");
			intergerRep(intBit);
			printf(")");
		}
		else if(floatBit > 0)
		{
			printf("*e(");
			intergerRep(-floatBit);
			printf(")");
		}
		else
		;
	}
	printf(" \n");
}


void binaryRepsentation2(string var)
{
	int pos = val.find('.', 0);
    int intpart = atoi(val.substr(0, pos).c_str());
    double decpart = atof(val.substr(pos, val.length()-pos).c_str());
    
    string intstr = "", decstr = "";
    while(intpart > 0){
        if(intpart&1) intstr = "1" + intstr;
        else intstr = "0" + intstr;
        intpart >>= 1;
    }
    while(decpart > 0){
        if(decstr.length() > 32) return "ERROR";
        decpart *= 2;
        if(decpart >= 1){
            decstr += "1";
            decpart -= 1;
        }
        else
            decstr += "0";
    }
    return intstr + "." + decstr;
}

int main()
{
	char s[] = "3.72";
	binaryRepsentation(s);
	return 0;
}