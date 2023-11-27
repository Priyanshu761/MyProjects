//Publisher Management System C++ 

#include <iostream>
using namespace std;

class Publication
{
protected:
    float price;

public:
    void getData()
    {
        cout << "Enter Price : " << endl;
        cin >> price;
    }
    void putData()
    {
        cout << "The price is : " << price << endl;
    }
};

class book : public Publication
{
private:
    int pageCount;

public:
    void getData()
    {
        cout << "Enter Number of Pages : " << endl;
        cin >> pageCount;
        Publication::getData();
    }
    void putData()
    {
        cout << "The Number of Pages is : " << pageCount << endl;
        Publication::putData();
    }
};

class tape : public Publication
{
private:
    float playTime;

public:
    void getData()
    {
        cout << "Enter Time in Minutes : " << endl;
        cin >> playTime;
        Publication::getData();
    }
    void putData()
    {
        cout << "The Time is : " << playTime << " mins" << endl;
        Publication::putData();
    }
};
int main()
{
    book b;
    tape t;
    int op;
    cout << "\n1]Book Information\n2]Tape Information\n3]Exit" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Please Enter your choice : " << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "--------Book information--------" << endl;
        b.getData();
        b.putData();
        break;
    case 2:
        cout << "------Tape Information--------" << endl;
        t.getData();
        t.putData();
        break;
    default:
        cout << "Thanks for using our Publication....." << endl;
        break;
    }

    return 0;
}