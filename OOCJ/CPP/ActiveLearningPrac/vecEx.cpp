#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v1;
	vector<int>::iterator it;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(1024);
	int arr[]={100,200,300,400};
	for(it=v1.begin();it!=v1.end();it++)
	{
		cout<<*it<<" "<<endl;
	}	
	for(int i=0;i<4;i++)
	{
		v1.push_back(arr[i]);
	}
	cout<<"-------------------------------------------------"<<endl;
	for(it=v1.begin();it!=v1.end();it++)
	{
		cout<<*it<<" "<<endl;
	}	
	cout<<"POPPED"<<endl;
	v1.pop_back();
	cout<<"-------------------------------------------------"<<endl;
	for(it=v1.begin();it!=v1.end();it++)
	{
		cout<<*it<<" "<<endl;
	}	
	return 0;
}
