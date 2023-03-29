#include<iostream>
using namespace std;
template <class T>
T maximum(T a,T b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int a=10;
	int b=20;
	int ans=maximum(a,b);
	cout<<ans<<" is greater"<<endl;
	return 0;
}

