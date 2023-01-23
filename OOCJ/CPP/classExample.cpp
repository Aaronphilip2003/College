#include <iostream>
using namespace std;
class Student
{
private:
    int roll_no = 12;

public:
    void showRoll()
    {
        cout << "Your roll number is: " << roll_no << endl;
    }
};

int main()
{
    Student s;
    s.showRoll();
}