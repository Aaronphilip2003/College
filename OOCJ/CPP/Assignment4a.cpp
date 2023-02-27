#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class Hotel
{
private:
    int cust_id;
    int income;
    string city;
    string room_type;

public:
    string cust_name;
    Hotel()
    {
        cust_id = 0;
        income = 0;
    }

    void accept();
    void display();
    int getage();
    int get_income();

    string getcity()
    {
        if (city != "Pune" && city != "Mumbai")
        {
            throw "City must be Pune or Mumbai!";
        }

        return city;
    }

    string getroom_type()
    {
        if (room_type != "Delux" && room_type != "Super Delux")
        {
            throw "Room Type must be Delux or Super Delux!";
        }

        return room_type;
    }
};

void Hotel::accept()
{
    cout << "Enter the name of the customer: " << endl;
    cin >> cust_name;
    cout << "Enter the ID of the customer: " << endl;
    cin >> cust_id;
    cout << "Enter the income of the customer: " << endl;
    cin >> income;
    cout << "Enter the name of the city: ";
    cin >> city;
    cout << "Enter Room Type (Delux or Super Delux): ";
    cin >> room_type;
}

void Hotel::display()
{
    cout << "Name of the customer: " << cust_name << endl;
    cout << "ID of the customer: " << cust_id << endl;
    cout << "Income of the customer: " << income << endl;
    cout << "City of the customer: " << city << endl;
    cout << "Room Type of the customer: " << room_type << endl;
}

int Hotel::getage()
{
    int age = 0;
    cout << "Enter the age of the customer: " << endl;
    cin >> age;
    if (age < 18 || age > 55)
    {
        throw("Age must be between 18 and 55");
    }

    return age;
}

int Hotel::get_income()
{
    if (income < 50000 || income > 100000)
    {
        throw("Income must be between 50000 and 100000");
    }

    return income;
}

int main()
{
    Hotel h;

    try
    {
        h.accept();
        h.display();
        int age = h.getage();
        int income = h.get_income();
        string city = h.getcity();
        cout << city << endl;
        string room_type = h.getroom_type();
        ofstream fout("hotel.txt", ios::app);
        fout << "Customer Name: " << h.cust_name << endl;
        fout << "Customer ID: " << cuserid << endl;
        fout << "Age: " << age << endl;
        fout << "Income: " << income << endl;
        fout << "City: " << city << endl;
        fout << "Room Type: " << room_type << endl;

        h.display();
    }
    catch (const char *msg)
    {
        cerr << "\nError: " << msg << endl;
    }
    return 0;
}