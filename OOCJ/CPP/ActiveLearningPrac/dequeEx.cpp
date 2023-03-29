#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int>deq={4,6,7};
	deque<int>::iterator it;
	for(it=deq.begin();it!=deq.end();it++)
	{
		cout<<*it<<endl;
	}

	return 0;
}
