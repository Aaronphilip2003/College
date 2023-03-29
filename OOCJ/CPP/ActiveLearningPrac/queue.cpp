#include<iostream>
#include<list>
using namespace std;
template <class T>
class Queue
{
	public:
		list <int> l1;
		list<int>::iterator it;
		T insert();
		T display();
};

template <class T>
T Queue<T>::insert()
{
	int a;
	cout<<"Enter a number:"<<endl;
	cin>>a;
	l1.push_back(a);
}
template <class T>
T Queue<T>::display()
{
	cout<<"The Queue is:"<<endl;
	for(it=l1.begin();it!=l1.end();it++)
	{
		cout<<*it<<" ";
	}
}



int main()
{
	Queue<int> q;
	q.insert();
	q.display();
	return 0;

}
