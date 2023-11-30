//Program for Scientific Calculator

#include <iostream>
#include <cmath>
using namespace std;

// Function Prototypes
void Power(float, float);
void Sine(float);
void Square(float);
void Cos(float);
void Tan(float);
void Log(float);
void Baselog(float);

int main()
{
    float a, b;
    int choice;

    do
    {
        cout << "WHAT YOU WANT TO FIND: " << endl;
        cout << "Press '1' for Power: " << endl;
        cout << "Press '2' for Sin: " << endl;
        cout << "Press '3' for Square: " << endl;
        cout << "Press '4' for Cos: " << endl;
        cout << "Press '5' for Tan: " << endl;
        cout << "Press '6' for Log: " << endl;
        cout << "Press '7' for Base Log: " << endl;
        cout << "Press '0' to Exit: " << endl;

        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the Number for Calculating its Power: ";
            cin >> a;
            cout << "Enter the Power for a Number: ";
            cin >> b;
            Power(a, b);
            break;

        case 2:
            cout << "Enter the Number for Calculating SIN: ";
            cin >> a;
            Sine(a);
            break;

        case 3:
            cout << "Enter the Number for Calculating Square: ";
            cin >> a;
            Square(a);
            break;

        case 4:
            cout << "Enter the Number for Calculating COS: ";
            cin >> a;
            Cos(a);
            break;

        case 5:
            cout << "Enter the Number for Calculating TAN: ";
            cin >> a;
            Tan(a);
            break;

        case 6:
            cout << "Enter the Number for Calculating LOG: ";
            cin >> a;
            Log(a);
            break;

        case 7:
            cout << "Enter the Number for Calculating LOG WITH BASE 10: ";
            cin >> a;
            Baselog(a);
            break;

        case 0:
            cout << "Exiting the Calculator." << endl;
            break;

        default:
            cout << "Invalid Choice! Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}

// Function Definitions

void Power(float x, float y)
{
    float p;
    p = pow(x, y);
    cout << "Power: " << p << endl;
}

void Sine(float x)
{
    float s;
    s = sin(x);
    cout << "Sin: " << s << endl;
}

void Square(float x)
{
    float sq;
    sq = sqrt(x);
    cout << "Square of a Given Value is: " << sq << endl;
}

void Cos(float x)
{
    float c;
    c = cos(x);
    cout << "COS: " << c << endl;
}

void Tan(float x)
{
    float t;
    t = tan(x);
    cout << "TAN: " << t << endl;
}

void Log(float x)
{
    float l;
    l = log(x);
    cout << "Natural Logarithm: " << l << endl;
}

void Baselog(float x)
{
    float bl;
    bl = log10(x);
    cout << "LOG with Base 10: " << bl << endl;
}
