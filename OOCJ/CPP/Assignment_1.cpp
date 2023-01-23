#include <iostream>
using namespace std;
class Student
{
private:
    int roll_no;
    int erp;
    string name;

public:
    void showData();
    void getData();
    void search(Student student_array[3], int search);
    Student();
    Student(string name, int roll, int erp);
    ~Student();
};

void Student::showData()
{
    cout << "Your Name is: " << name << endl;
    cout << "Your Roll Number is: " << roll_no << endl;
    cout << "Your ERP Number is: " << erp << endl;
}

void Student::getData()
{
    cout << "Enter your name: " << endl;
    cin >> name;
    cout << "Enter your roll number: " << endl;
    cin >> roll_no;
    cout << "Enter your erp: " << endl;
    cin >> erp;
}

Student::Student()
{
    name = "";
    roll_no = 0;
    erp = 0;
}

Student::Student(string n, int r, int e)
{
    name = n;
    roll_no = r;
    erp = e;
}
Student::~Student()
{
    cout << "Destructor was called !" << endl;
}

void Student::search(Student student_array[3], int search)
{
    int pos = -1;
    for (int i = 0; i < 5; i++)
    {
        if (student_array[i].roll_no == search)
        {
            pos = i;
            break;
        }
    }
    cout << "Name of searched student:" << student_array[pos].name << endl;
    cout << "Roll Number of searched student:" << student_array[pos].roll_no << endl;
    cout << "ERP Number of searched student:" << student_array[pos].erp << endl;
}

int main()
{
    Student student_array[5];
    int search;
    // Student s1;
    // s1.showData(); // Default constructor
    // Student s2("Aaron", 2, 1032210163);
    // s2.showData(); // Parameterized constructor
    // Student s3(s2);
    // s3.showData(); // Copy Constructor
    cout << "Enter data for 5 students:" << endl;
    for (int i = 0; i < 5; i++)
    {
        student_array[i].getData();
    }
    // for (int i = 0; i < 5; i++)
    // {
    //     student_array[i].showData();
    // }
    cout << "Enter roll no to be searched:" << endl;
    cin >> search;
    student_array[0].search(student_array, search);
}