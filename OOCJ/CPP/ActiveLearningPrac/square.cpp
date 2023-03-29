#include<iostream>
using namespace std;

template <class T>

T sq(T a)
{
	return a*a;
}


int main()
{
	int a=19;
	float b=29.9F;
	int ans1=0;
	float ans2=0.0F;
	ans1=sq(a);
	ans2=sq(b);
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	return 0;
}
