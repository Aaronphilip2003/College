
#include <iostream>
#include <fstream>
using namespace std;

class Hotel
{
private:
    string cust_name;
    int cust_id;
    int cust_age;
    int income;
    string city;
    string room_type;

public:
    Hotel();
    void accept();
    void display();
    void getAge();
    void getIncome();
    void getCity();
    void getRoomType();
};

Hotel::Hotel()
{
    cust_name = "";
    cust_id = 0;
    cust_age = 0;
    income = 0;
    city = "";
    room_type = "";
};

void Hotel::accept()
{
    cout << "Enter customer id ";
    cin >> cust_id;

    cout << "Enter your name ";
    cin >> cust_name;

    getAge();
    getIncome();
    getCity();
    getRoomType();
}

void Hotel::getAge()
{
    cout << "Enter your age ";
    cin >> cust_age;
    try
    {
        if (!(cust_age >= 18 && cust_age <= 55))
        {
            throw(cust_age);
        }
    }
    catch (int a)
    {
        cout << "Age not eligible." << endl;
        getAge();
    }
}

void Hotel::getIncome()
{
    cout << "Enter your income ";
    cin >> income;
    try
    {
        if (!(income >= 50000 && income <= 100000))
        {
            throw(income);
        }
    }
    catch (int i)
    {
        cout << "Incorrect Income" << endl;
        getIncome();
    }
}

void Hotel::getCity()
{
    cout << "Enter your city ";
    cin >> city;
    try
    {
        if (city == "pune" || city == "mumbai")
        {
            cout << "Correct City Selected" << endl;
        }
        else
        {
            throw(city);
        }
    }
    catch (string c)
    {
        cout << "Incorrect City" << endl;
        getCity();
    }
}

void Hotel::getRoomType()
{
    cout << "Enter the room required ";
    cin >> room_type;
    try
    {
        if (room_type == "delux" || room_type == "super delux")
        {
            cout << "Correct Room type selected" << endl;
        }
        else
        {
            throw(room_type);
        }
    }
    catch (string r)
    {
        cout << "Room type must be Delux or Super Delux" << endl;
        getRoomType();
    }
}

void Hotel::display()
{
    cout << "ID: " << cust_id << endl;
    cout << "Name: " << cust_name << endl;
    cout << "Age: " << cust_age << endl;
    cout << "City: " << city << endl;
    cout << "Income: " << income << endl;
    cout << "Room: " << room_type << endl;
}
int main()
{
    int n;
    cout << "Enter the number of records:" << endl;
    cin >> n;
    ifstream fin;
    ofstream fout;
    fout.open("hotelinfo.txt", ios::app);
    Hotel h;
    while (n != 0)
    {
        h.accept();
        h.display();
        fout.write((char *)&h, sizeof(h));
        fin.open("hotelinfo.txt", ios::out);
        fin.read((char *)&h, sizeof(h));
        h.display();
        n--;
    }
    fout.close();
    return 0;
}