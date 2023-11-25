// ATM MACHINE MANAGEMENT----

#include <iostream>
using namespace std;

class ATM
{
private:
    int balance;
    int pin_code, success;

public:
    ATM(int bal, int pin)
    {
        balance = bal;
        pin_code = pin;
    }
    int getBalance()
    {
        return balance;
    }
    int withdraw(int amount, int pin)
    {
        if (pin != pin_code)
        {
            return false;
        }

        if (amount > balance)
        {
            return false;
        }
        else
        {
            balance = balance - amount;
            return true;
        }
    }
    void deposit(int amount)
    {
        balance = balance + amount;
    }
    int transfer(int amt, ATM receiver, int pin)
    {
        if (pin != pin_code)
        {
            return false;
        }
        success = withdraw(amt, pin);
        if (success)
        {
            receiver.deposit(amt);
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    ATM atm(1000, 1234);
    int ch, amt, success, pin;
    char op;
    do
    {
        system("cls");
        cout << "\n1]View Balance\n2]Cash Withdraw\n3]Cash Deposit\n4]Cash Transfer\n5]Exit" << endl;
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Your Balance is : " << atm.getBalance();
            break;
        case 2:
            cout << "Your available balance is : " << atm.getBalance();
            cout << "Enter your amount to withdraw : " << endl;
            cin >> amt;
            success = atm.withdraw(amt, 1234);
            if (success)
            {
                cout << "Withdraw successful...." << endl;
                cout << "Remaining balance is : " << atm.getBalance();
            }
            else
            {
                cout << "Insufficient Balance...." << endl;
            }
            break;
        case 3:
            cout << "Enter the amount to deposit : " << endl;
            cin >> amt;
            atm.deposit(amt);
            cout << "Deposit successful...." << endl;
            cout << "New Balance is : " << atm.getBalance();
            break;
        case 4:
            cout << "Your available balance is : " << atm.getBalance();
            cout << "\nEnter the amount to transfer : " << endl;
            cin >> amt;
            cout << "Enter your pin code : " << endl;
            cin >> pin;
            success = atm.transfer(amt, atm, pin);
            if (success)
            {
                cout << "Transfer complete successfully...." << endl;
            }
            else
            {
                cout << "Insufficient balance or invalid pin....." << endl;
            }
            break;
        case 5:
            cout << "Thanks for using ATM.... " << endl;
            exit(1);
            break;
        default:
            cout << "Invalid Choice....." << endl;
            break;
        }
        cout << "\nDo you want to try another transaction : " << endl;
        cin >> op;
    } while (op == 'Y' || op == 'y');
    return 0;
}