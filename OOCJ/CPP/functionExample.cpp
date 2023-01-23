#include <iostream>
using namespace std;

void print(string arg1)
{
    cout << "Function printed this: " << arg1 << endl;
}

int main()
{
    string name;
    cout << "Enter your name:" << endl;
    cin >> name;
    print(name);
    return 0;
}