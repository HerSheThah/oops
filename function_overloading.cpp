// MAXIMUM 2 AND 3 NUMBERS WITH THE SAME FUNCTION NAME
#include<iostream>
using namespace std;
int max(int x, int y)
{
	if(x>y)
		return x;
	return y;
}
int max(int a, int b, int c)
{
	if(a>b)
	{
		if(a>c)
			return a;
		return c;
	}
	else{
		if(b>c)
			return b;
		return c;
	}
}

int main()
{
	cout<<max(4, 5)<<endl;
	cout<<max(3, 8, 1);
}

