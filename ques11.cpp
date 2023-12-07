// CONTACAT MANAGEMENT SYSTEM C++

#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>
using namespace std;

class contact
{
private:
    long ph;
    char name[30], add[30], email[30];

public:
    void createContact()
    {
        cout << "Phone : ";
        cin >> ph;

        cout << "Name : ";
        cin.ignore();
        cin >> name;

        cout << "Address : ";
        cin.ignore();
        cin >> add;

        cout << "Email address : ";
        cin.ignore();
        cin >> email;

        cout << "\n";
    }

    void showContact()
    {
        cout << endl
             << "Phone # : " << ph;
        cout << endl
             << "Name : " << name;
        cout << endl
             << "Address : " << add;
        cout << endl
             << "Email Address : " << email;
    }

    long getPhone()
    {
        return ph;
    }
    char *getName()
    {
        return name;
    }
    char *getAddress()
    {
        return add;
    }
    char *getEamil()
    {
        return email;
    }
};

fstream fp;
contact cont;

void saveContact()
{
    fp.open("contactBook.dat", ios::out | ios::app); // Opens "contactBook.dat" in output and append mode

    cont.createContact(); // Assuming this function gathers and creates a new contact in the 'cont' object

    fp.write((char *)&cont, sizeof(contact)); // Writes the content of 'cont' into the file

    fp.close(); // Closes the file stream

    // Displaying a success message
    cout << endl
         << endl
         << "Contact Has Been Successfully Created...";

    getchar(); // Pauses to hold the console open for user interaction
}

void showAllContacts()
{
    system("cls"); // Clears the console screen for a clean display

    // Printing a header for the list of contacts
    cout << "\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n";

    fp.open("contactBook.dat", ios::in); // Opens the file "contactBook.dat" in input mode

    // Looping through the file content to read and display each contact
    while (fp.read((char *)&cont, sizeof(contact)))
    {
        cont.showContact(); // Displays details of the contact using cont.showContact()
        cout << endl
             << "=================================================\n"
             << endl;
    }

    fp.close(); // Closes the file after displaying all contacts
}

void displayContact(int num)
{

    bool found; // A boolean variable to track whether a contact with the given number is found
    int ch;     // An integer variable (not currently used in this function)

    found = false; // Initializing 'found' as false initially, assuming the contact is not found

    fp.open("contactBook.dat", ios::in); // Opening the file "contactBook.dat" for reading

    // Looping through the file content to find a contact with the given phone number
    while (fp.read((char *)&cont, sizeof(contact)))
    {
        if (cont.getPhone() == num)
        {
            system("cls");      // Clearing the console screen
            cont.showContact(); // Displaying the contact information
            found = true;       // Setting 'found' to true as the contact is found
        }
    }

    fp.close(); // Closing the file after reading

    // If the contact with the given number is not found, display a message
    if (found == false)
    {
        cout << "\n\nNo record found...";
    }

    getchar(); // Pausing to hold the console open for the user
}

void editContact()
{
    int num;            // Variable to store the contact number to be edited
    bool found = false; // Boolean flag to track if the contact was found
    system("cls");      // Clearing the console screen

    // Prompting the user to enter the contact number to be edited
    cout << "..::Edit contact\n===============================\n\n\t..::Enter the number of contact to edit:";
    cin >> num;

    fp.open("contactBook.dat", ios::in | ios::out); // Opening the file in read and write mode

    // Looping through the file content to find and edit the contact
    while (fp.read((char *)&cont, sizeof(contact)) && found == false)
    {
        if (cont.getPhone() == num)
        {
            cont.showContact(); // Displaying the details of the contact to be edited
            cout << "\nPlease Enter The New Details of Contact: " << endl;
            cont.createContact(); // Taking new details for the contact

            int pos = -1 * sizeof(cont);           // Calculating the position to overwrite the existing contact
            fp.seekp(pos, ios::cur);               // Moving the file pointer to the position to write the updated contact
            fp.write((char *)&cont, sizeof(cont)); // Writing the updated contact details to the file

            cout << endl
                 << endl
                 << "\t Contact Successfully Updated...";
            found = true; // Setting found to true as the contact is updated
        }
    }
    fp.close(); // Closing the file after editing

    // If the contact was not found, display a message
    if (found == false)
        cout << endl
             << endl
             << "Contact Not Found...";
}
void deleteContact()
{
    int num;
    system("cls"); // Clears the console screen

    cout << endl
         << endl
         << "Please Enter The contact #: ";
    cin >> num; // Reads the contact number to be deleted from the user

    fp.open("contactBook.dat", ios::in | ios::out); // Opens "contactBook.dat" in both input and output modes
    fstream fp2;                                    // Creates a new file stream object

    fp2.open("Temp.dat", ios::out); // Opens "Temp.dat" in output mode

    fp.seekg(0, ios::beg); // Sets the get pointer to the beginning of "contactBook.dat"

    // Loop through "contactBook.dat" to copy contacts except the one to be deleted to "Temp.dat"
    while (fp.read((char *)&cont, sizeof(contact)))
    {
        if (cont.getPhone() != num)
        {
            fp2.write((char *)&cont, sizeof(contact)); // Write the contact details to "Temp.dat"
        }
    }

    fp2.close(); // Close "Temp.dat"
    fp.close();  // Close "contactBook.dat"

    remove("contactBook.dat");             // Delete the original "contactBook.dat"
    rename("Temp.dat", "contactBook.dat"); // Rename "Temp.dat" to "contactBook.dat"

    cout << endl
         << endl
         << "\tContact Deleted..."; // Display confirmation message
}

int main(int argc, char *argv[])
{
    system("cls");
    system("color 03");
    cout << "\t\t\t\t*\t*";
    cout << "\t\t\t\t**\t**";
    cout << "\t\t\t\t***\t***";
    cout << "\t\t\t\t****\t****";
    cout << "\t\t\t\t*****\t*****";
    cout << "\t\t\t\t******\t******";
    cout << "\t\t\t\t*******\t*******";
    cout << "\t\t\t\t*******\t*******";
    cout << "\t\t\t\t******\t******";
    cout << "\t\t\t\t*****\t*****";
    cout << "\t\t\t\t****\t****";
    cout << "\t\t\t\t***\t***";
    cout << "\t\t\t\t**\t**";
    cout << "\t\t\t\t*\t*";

    for (;;)
    {
        int ch;
        cout << "\n\t **** Welcome to Contact Management System ****";
        cout << "\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t";
        cout << "Enter the choice:";

        cin >> ch;

        switch (ch)
        {
        case 0:
            cout << "\n\n\t\tThank you for using CMS...";
            exit(0);
            break;
            break;
            break;
        case 1:
            saveContact();
            break;
        case 2:
            showAllContacts();
            break;
        case 3:
            int num;
            system("cls");
            cout << "\n\n\tPhone: ";
            cin >> num;
            displayContact(num);
            break;
        case 4:
            editContact();
            break;
        case 5:
            deleteContact();
            break;
        default:
            break;
        }

        int opt;
        cout << "\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n";

        cin >> opt;

        switch (opt)

        {

        case 1:
            system("cls");
            continue;

        case 0:

            exit(0);
        }
    }
    return 0;
}