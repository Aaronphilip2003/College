#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v1;
	int cont=0;
	cout<<"----------MENU----------"<<endl;
	cout<<"1-Add Item"<<endl;
	cout<<"2-Remove Item"<<endl;
	cout<<"3-Find Item"<<endl;
	cout<<"4-Sort List"<<endl;
	cout<<"5-Print list"<<endl;
	cout<<"6-Exit"<<endl;
	cout<<"------------------------"<<endl;
	do
	{
	cout<<"Enter your choice:"<<endl;
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				int elem=0;
				cout<<"Enter the element to be added:"<<endl;
				cin>>elem;
				v1.push_back(elem);
			}
		break;

		case 2:
			{
				v1.pop_back();
			}
		break;
		case 3:
			{
				vector<int>::iterator it;
				vector<int>::iterator begin;
				begin=v1.begin();
				it=v1.begin();
				int len=v1.size();
				int *search;
				int search_elem;
				cout<<"Enter the element to be searched:"<<endl;
				cin>>search_elem;
				it=find(v1.begin(),v1.end(),search_elem);
				cout<<"Element found:"<<*it<<endl;
			 	cout<<"Element found at:"<<it-begin<<endl;
			}
		break;
		case 4:
			{
				sort(v1.begin(),v1.end());
			}
		break;
		case 5:
			{
				cout<<"----------LIST----------"<<endl;
				vector<int>::iterator it;
				for(it=v1.begin();it!=v1.end();it++)
				{
					cout<<*it<<endl;
				}
				cout<<"------------------------"<<endl;
			}
		break;

	}
	cout<<"Do you want to continue? (0/1)"<<endl;
	cin>>cont;
	}while(cont!=1);

}

