#include<iostream>
using namespace std;

template <class T>
T absVal(T a)
{
	return (a<0)?-a:a;
}

int main()
{
	int val=0;
	int ans=0;
	cout<<"Enter a number:"<<endl;
	cin>>val;
	ans=absVal(val);
	cout<<"Absolute Value:"<<ans<<endl;
	return 0;
}
