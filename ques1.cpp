// Bank Management System In C++

#include <iostream>
using namespace std;

class BankAccount
{
private:
    int acno;
    int balance;

public:
    void openAccount()
    {
        cout << "Enter account number : " << endl;
        cin >> acno;
        cout << "Enter account balance : " << endl;
        cin >> balance;
    }
    void showAccount()
    {
        cout << acno << " , " << balance << endl;
    }
    void deposit()
    {
        int amt;
        cout << "Enter the amount you want to deposit ? " << endl;
        cin >> amt;
        balance += amt;
        cout << "Your amount seccessfully deposited and the new balance is : " << endl;
        showAccount();
    }
    void withdraw()
    {
        int amt;
        cout << "Enter the amount you want to withdraw ? " << endl;
        cin >> amt;
        if (amt > balance)
        {
            cout << "Sorry , you don't have suffcient balance... " << endl;
        }
        else
        {
            balance -= amt;
            cout << "Your money successfully withdrawled , remaining balance is : " << endl;
            showAccount();
        }
    }
    int search(int);
};

int BankAccount::search(int an)
{
    if (an == acno)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
int main()
{
    BankAccount c[3];
    int ch, an, found;
    for (int i = 0; i <= 2; i++)
    {
        c[i].openAccount();
    }
    do
    {
        cout << "Main Menu\n1]Show all Accounts\n2]Search account by Account Number\n3]Deposit Money\n4]Withdrawl Money\n5]Exit" << endl;
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (int i = 0; i <= 2; i++)
            {
                c[i].showAccount();
            }
            break;
        case 2:
            cout << "Enter the Account number you are searching for ? " << endl;
            cin >> an;
            for (int i = 0; i <= 2; i++)
            {
                found = c[i].search(an);
                if (found)
                {
                    c[i].showAccount();
                    break;
                }
            }
            if (!found)
            {
                cout << "No records found...." << endl;
            }
            break;
        case 3:
            cout << "Enter the account number you are seraching for deposit ? " << endl;
            cin >> an;
            for (int i = 0; i <= 2; i++)
            {
                found = c[i].search(an);
                if (found)
                {
                    c[i].showAccount();
                    c[i].deposit();
                    break;
                }
            }
            if (!found)
            {
                cout << "No records found...." << endl;
            }
            break;
        case 4:
            cout << "Enter the account number you are searching for withdrawl ? " << endl;
            cin >> an;
            for (int i = 0; i <= 2; i++)
            {
                found = c[i].search(an);
                if (found)
                {
                    c[i].showAccount();
                    c[i].withdraw();
                    break;
                }
            }
            if (!found)
            {
                cout << "No records found...." << endl;
            }
            break;
        case 5:
            cout << "Thanks for using our service , Have a nice day " << endl;
            break;
        default:
            cout << "Wrong choice " << endl;
            break;
        }
    } while (ch != 5);

    return 0;
}