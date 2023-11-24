// Vehicle Management System

#include <iostream>
using namespace std;

class Vehicle
{
private:
    string make, model;
    int year;

public:
    void inputDta()
    {
        cout << "Enter company Name : " << endl;
        cin >> make;
        cout << "Enter Model : " << endl;
        cin >> model;
        cout << "Enter Year : " << endl;
        cin >> year;
    }
    void display()
    {
        cout << "Make : " << make << endl;
        cout << "Model : " << model << endl;
        cout << "Year : " << year << endl;
    }
};

class Car : public Vehicle
{
private:
    int numDoor;

public:
    void inputData()
    {
        cout << "Enter the number of doors : " << endl;
        cin >> numDoor;
    }
    void display()
    {
        cout << "Doors : " << numDoor << endl;
    }
};

class ToyotaCar : public Car
{
private:
    string trimLevel;

public:
    void inputData()
    {
        Vehicle::inputDta();
        Car::inputData();
        cout << "Enter the trim level : " << endl;
        cin >> trimLevel;
    }
    void display()
    {
        Vehicle::display();
        Car::display();
        cout << "Trim Level : " << trimLevel << endl;
    }
};
int main()
{
    ToyotaCar myCar;
    cout << "----------Input Car Info--------------" << endl;
    myCar.inputData();
    cout << "----------Output Car Info--------------" << endl;
    myCar.display();
    return 0;
}