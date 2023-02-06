/*
Develop a CPP Program to create a abstract bases class Employee and derived
classes SalariedEmployee, HourlyEmployee and CommissionedEmployee

Class Employee has datamembers string e_name, integer employeeID and has a default
and a parameterized constructor, it has 2 virtual functions, accept() to receive data
member values from the user and display() function to display the value of the data
members and a pure virtual function earnings().

SalariedEmployee class has data members double weeklySalary, a default and a
parameterized constructor. The function earning displays weeklySalary.

HourlyEmployee has datamembers double wages, double hours and double hourlySalary
and has a default and a parameterised constructor and a function earnings.

earnings()
if hours<40 then hourlySalary=hours*wages
else
hourlySalary=40*wages+(hours-40)*wages*1.5

CommissionEmployee has datamembers double grossSales, double commissionRate and double
commisionSalary and default and parameterised constructor

earnings()
commissionSalary=grossSales*commissionRate

Create objects of the derived classes and display their earnings

*/

#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string e_name;
    int employeeID;

public:
    Employee();
    ~Employee();
    Employee(string name, int e_id);

    void accept();
    void display();
    void earnings();
};

Employee ::Employee()
{
    e_name = "";
    employeeID = 0;
    cout << "Default Constructor of the base class called!" << endl;
}

Employee::~Employee()
{
    cout << "Destructor of the base class called!" << endl;
}

Employee::Employee(string name, int e_id)
{
    e_name = name;
    employeeID = e_id;
    cout << "Parameterised Constructor of the base class called!" << endl;
}

void Employee::accept()
{
    cout << "Enter the Employee name:" << endl;
    cin >> e_name;
    cout << "Enter the Employee ID:" << endl;
    cin >> employeeID;
}

void Employee::display()
{
    cout << "Name of the employee:" << e_name << endl;
    cout << "ID of the employee:" << employeeID << endl;
}

void Employee::earnings()
{
    cout << "Function earnings of the base class is called!" << endl;
}

class SalariedEmployee : public Employee
{
private:
    double weeklySalary;

public:
    SalariedEmployee();
    ~SalariedEmployee();
    SalariedEmployee(double ws);
    void earnings();
};

SalariedEmployee::SalariedEmployee()
{
    weeklySalary = 0;
    cout << "Default Constructor of SalariedEmployee was called!" << endl;
}

SalariedEmployee::~SalariedEmployee()
{
    cout << "Destructor of SalariedEmployee was called!" << endl;
}

SalariedEmployee::SalariedEmployee(double ws)
{
    weeklySalary = ws;
    cout << "Parameterised constructor of SalariedEmployee was called!" << endl;
}

void SalariedEmployee::earnings()
{
    cout << "Earnings of the week:" << weeklySalary << endl;
}

class HourlyEmployee : public Employee
{
private:
    double wages, hours, hourlySalary;

public:
    HourlyEmployee();
    ~HourlyEmployee();
    HourlyEmployee(double w, double h, double hs);
    void earnings();
};

HourlyEmployee::HourlyEmployee()
{
    wages = 0;
    hours = 0;
    hourlySalary = 0;
    cout << "Default Constructor of HourlyEmployee called!" << endl;
}

HourlyEmployee::~HourlyEmployee()
{
    cout << "Destructor of HourlyEmployee class called!" << endl;
}

// HourlyEmployee::HourlyEmployee(double w, double h, double hs) : Employee("Aaron", 12345)
HourlyEmployee::HourlyEmployee(double w, double h, double hs)
{
    accept();
    wages = w;
    hours = h;
    hourlySalary = hs;
    cout << "Parameterised Constructor of HourlyEmployee called!" << endl;
}

void HourlyEmployee::earnings()
{
    if (hours < 40)
    {
        hourlySalary = hours * wages;
    }
    else
    {
        hourlySalary = hours + wages + ((hours - 40) * 1.5);
    }

    cout << "Hourly Salary:" << hourlySalary << endl;
}

class CommissionedEmployee : public Employee
{
private:
    double grossSales, commissionRate, commissionSalary;

public:
    CommissionedEmployee();
    ~CommissionedEmployee();
    CommissionedEmployee(double gs, double cr, double cs);
    void earnings();
};

CommissionedEmployee::CommissionedEmployee()
{
    cout << "Default constructor of CommissionedEmployee called!" << endl;
    grossSales = 0;
    commissionRate = 0;
    commissionSalary = 0;
}

CommissionedEmployee::~CommissionedEmployee()
{
    cout << "Destructor of CommissionEmployee called!" << endl;
}

CommissionedEmployee::CommissionedEmployee(double gs, double cr, double cs)
{
    accept();
    cout << "Parameterised Constructor of CommissionedEmployee called!" << endl;
    grossSales = gs;
    commissionRate = cr;
    commissionSalary = cs;
}

void CommissionedEmployee::earnings()
{
    commissionSalary = grossSales * commissionRate;
    cout << "Commissioned Salary:" << commissionSalary << endl;
}

int main()
{
    Employee e1;
    e1.display();
    e1.earnings();
    Employee e2("Aaron", 12345);
    e2.display();
    e2.earnings();

    SalariedEmployee se1;
    se1.earnings();
    SalariedEmployee se2(1000);
    se2.earnings();

    HourlyEmployee he1(10, 20, 30);
    he1.display();
    he1.earnings();

    CommissionedEmployee ce1(10, 20, 30);
    ce1.display();
    ce1.earnings();

    return 0;
}