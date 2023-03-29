#include<iostream>
using namespace std;

template <class T>
class Operation
{
	public:
		T Add(T,T);
		T Subtract(T,T);
};

template <class T>
T Operation<T>::Add(T a,T b)
{
	return a+b;
}	

template <class T>
T Operation<T>::Subtract(T a,T b)
{
	return b-a;
}


int main()
{
	Operation<int>obj1;
	int num1=10;
	int num2=20;
	int ans1=0;
	int ans2=0;
	ans1=obj1.Add(num1,num2);
	ans2=obj1.Subtract(num1,num2);
	cout<<"Sum:"<<ans1<<endl;
	cout<<"Difference:"<<ans2<<endl;
	return 0;
}
