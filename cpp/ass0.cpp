#include <iostream>
#include <string>
using namespace std;

//---------------- Rectangle ----------------
class Rectangle
{
public:
    int length, breadth;

    void read()
    {
        cout << "Enter Length: ";
        cin >> length;
        cout << "Enter Breadth: ";
        cin >> breadth;
    }

    void area()
    {
        cout << "Area = " << length * breadth << endl;
    }

    void perimeter()
    {
        cout << "Perimeter = " << 2 * (length + breadth) << endl;
    }

    void display()
    {
        area();
        perimeter();
    }
};

//---------------- Car ----------------
class Car
{
public:
    string model;
    string brand;
    float mileage;

    void read()
    {
        cout << "Enter Brand: ";
        cin >> brand;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Mileage: ";
        cin >> mileage;
    }

    void display()
    {
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
        cout << "Mileage : " << mileage << " km/l" << endl;
    }

    void checkMileage()
    {
        if (mileage > 20)
            cout << "Mileage is greater than 20 km/l" << endl;
        else
            cout << "Mileage is not greater than 20 km/l" << endl;
    }
};

//---------------- Mobile ----------------
class Mobile
{
public:
    string brand;
    string model;
    float price;

    void read()
    {
        cout << "Enter Brand: ";
        cin >> brand;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Price: ";
        cin >> price;
    }

    void display()
    {
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
        cout << "Price : " << price << endl;
    }

    void discount()
    {
        float newPrice;

        newPrice = price - (price * 10 / 100);

        cout << "Price after 10% Discount = " << newPrice << endl;
    }
};

//---------------- Time ----------------
class Time
{
public:
    int hour;
    int minute;
    int second;

    void input()
    {
        cout << "Enter Hours: ";
        cin >> hour;

        cout << "Enter Minutes: ";
        cin >> minute;

        cout << "Enter Seconds: ";
        cin >> second;
    }

    void display()
    {
        cout << "Time = " << hour << ":" << minute << ":" << second << endl;
    }
};

//---------------- Player ----------------
class Player
{
public:
    string name;
    int runs;
    int matches;

    void input()
    {
        cout << "Enter Player Name: ";
        cin >> name;

        cout << "Enter Runs Scored: ";
        cin >> runs;

        cout << "Enter Matches Played: ";
        cin >> matches;
    }

    void average()
    {
        float avg;

        avg = (float)runs / matches;

        cout << "Batting Average = " << avg << endl;
    }

    void display()
    {
        cout << "Player Name : " << name << endl;
        cout << "Runs : " << runs << endl;
        cout << "Matches : " << matches << endl;

        average();
    }
};

//---------------- Main ----------------
int main()
{
    Rectangle r;
    Car c;
    Mobile m;
    Time t;
    Player p;

    cout << "----- Rectangle -----" << endl;
    r.read();
    r.display();

    cout << endl;

    cout << "----- Car -----" << endl;
    c.read();
    c.display();
    c.checkMileage();

    cout << endl;

    cout << "----- Mobile -----" << endl;
    m.read();
    m.display();
    m.discount();

    cout << endl;

    cout << "----- Time -----" << endl;
    t.input();
    t.display();

    cout << endl;

    cout << "----- Player -----" << endl;
    p.input();
    p.display();

    return 0;
}