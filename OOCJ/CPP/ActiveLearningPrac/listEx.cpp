#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> l1={1,2,3,4,5};
	list<int> l2={10,20,30,40,40,40};
	list<int>::iterator it;
	for(it=l1.begin();it!=l1.end();it++)
	{
		cout<<*it<<endl;
	}
	l1.reverse();
	cout<<"--------------------------------"<<endl;
	for(it=l1.begin();it!=l1.end();it++)
	{
		cout<<*it<<endl;
	}
	l1.merge(l2);
	cout<<"--------------------------------"<<endl;
	for(it=l1.begin();it!=l1.end();it++)
	{
		cout<<*it<<endl;
	}
	l1.unique();
	cout<<"--------------------------------"<<endl;
	for(it=l1.begin();it!=l1.end();it++)
	{
		cout<<*it<<endl;
	}
	return 0;
}
