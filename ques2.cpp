//Registration and Login Form in C++

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
private:
    string password, username;

public:
    User(string name, string pass)
    {
        username = name;
        password = pass;
    }
    string getUsername()
    {
        return username;
    }
    string getPassword()
    {
        return password;
    }
};

class UserManager
{
private:
    vector<User> users; // create vector of objects
public:
    void RegisterUser()
    {
        string username, password;
        cout << "Enter username : " << endl;
        cin >> username;
        cout << "Enter password : " << endl;
        cin >> password;
        User newUser(username, password);
        users.push_back(newUser);
        cout << "User register successfully......" << endl;
    }
    bool LoginUser(string name, string pass)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == name && users[i].getPassword() == pass)
            {
                cout << "Login Successfully......" << endl;
                return true;
            }
        }
        cout << "Invalid username or Password..." << endl;
        return false;
    }
    void showUserList()
    {
        cout << "-----Users List------" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << users[i].getUsername() << endl;
        }
    }
    void searchUser(string username)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username)
            {
                cout << "User Found " << endl;
            }
        }
    }
    void deleteUer(string username)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username)
            {
                users.erase(users.begin() + i);
                cout << "User remove Successfully..." << endl;
            }
        }
    }
};
int main()
{
    UserManager usermanage;
    int op;
    char choice;
    do
    {
        system("cls");
        cout << "......Main menu.....\n1]Register User\n2]Login\n3]Show User List\n4]Search User\n5]Delete User\n6]Exit" << endl;
        string username, password;
        cout << "Enter your choice " << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            usermanage.RegisterUser();
            break;
        case 2:
            cout << "Enter user : " << endl;
            cin >> username;
            cout << "Enter password : " << endl;
            cin >> password;
            usermanage.LoginUser(username, password);
            break;
        case 3:
            usermanage.showUserList();
            break;
        case 4:
            cout << "Enter username : " << endl;
            cin >> username;
            usermanage.searchUser(username);
            break;
        case 5:
            cout << "Enter username : " << endl;
            cin >> username;
            usermanage.deleteUer(username);
            break;
        case 6:
            exit(1);
        default:
            break;
        }
        cout << "Do you want to contiue [Yes/No] ? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}