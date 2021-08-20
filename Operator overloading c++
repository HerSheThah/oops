#include<iostream>
using namespace std;
class complex{
	int real, img;
	public:
		complex(int r=0, int i=0)
		{
			real=r;
			img=i;
		}
		complex operator +(complex ob)
		{
			complex sum;
			sum.real=real+ob.real;
			sum.img=img+ob.img;
			return sum;
		}
		complex display()
		{
			cout<<real<<"+i"<<img;	
		}	
};
int main()
{
	complex c(10, 3), d(1, 2);
	complex e=c+d;
	e.display();
}
