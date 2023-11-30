#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class GradeCalculator
{
private:
    vector<float> credit;
    vector<float> point;

public:
    void calculateGPA();
    void calculateCGPA();
    void method();
};

void GradeCalculator::calculateGPA()
{
    int q;
    system("cls");
    cout << "-------------- GPA Calculating -----------------" << endl;
    cout << "How many subject's points do you want to calculate? : ";
    cin >> q;

    credit.resize(q);
    point.resize(q);

    cout << endl;
    for (int i = 0; i < q; i++)
    {
        cout << "Enter the credit for subject " << i + 1 << ": ";
        cin >> credit[i];
        cout << endl;
        cout << "Enter the point of subject " << i + 1 << ": ";
        cin >> point[i];
        cout << "-----------------------------------\n\n"
             << endl;
    }

    float sum = 0, tot;
    for (int j = 0; j < q; j++)
    {
        tot = credit[j] * point[j];
        sum += tot;
    }

    float totCr = 0;
    for (int k = 0; k < q; k++)
    {
        totCr += credit[k];
    }

    cout << "\n\n\nTotal Points: " << sum << " . Total Credits: " << totCr << " .Total GPA: " << sum / totCr << " ." << endl;

    int inmenu;
    cout << "\n\n\n1. Calculate Again" << endl;
    cout << "2. Go Back to Main Menu" << endl;
    cout << "3. Exit This App \n\n"
         << endl;
    cout << "Your Input: " << endl;
    cin >> inmenu;

    switch (inmenu)
    {
    case 1:
        calculateGPA();
        break;
    case 2:
        break;
    case 3:
        exit(EXIT_SUCCESS);
    default:
        cout << "\n\nYou have Entered Wrong Input!Please Choose Again!" << endl;
        break;
    }
}

void GradeCalculator::calculateCGPA()
{
    system("cls");
    int l;
    cout << "-------------- CGPA Calculating -----------------\n\n"
         << endl;
    cout << "How many semester results do you want input? :";
    cin >> l;
    cout << "\n\n"
         << endl;

    vector<float> semrs(l);
    int i;

    for (i = 0; i < l; i++)
    {
        cout << " Enter Semester " << i + 1 << " Result(GPA): ";
        cin >> semrs[i];
        cout << "\n"
             << endl;
    }

    float semtot = 0;
    for (int j = 0; j < l; j++)
    {
        semtot += semrs[j];
    }

    cout << "******** Your CGPA is " << semtot / l << " **********" << endl;

    int inmenu;
    cout << "\n\n\n1. Calculate Again" << endl;
    cout << "2. Go Back to Main Menu" << endl;
    cout << "3. Exit This App \n\n"
         << endl;
    cout << "Your Input: " << endl;
    cin >> inmenu;

    switch (inmenu)
    {
    case 1:
        calculateCGPA();
        break;
    case 2:
        break;
    case 3:
        exit(EXIT_SUCCESS);
    default:
        cout << "\n\nYou have Entered Wrong Input!Please Choose Again!" << endl;
        break;
    }
}

void GradeCalculator::method()
{
    system("cls");
    cout << "--------------- Method of Calculating GPA & CGPA ---------------\n\n"
         << endl;
    cout << " GPA = Sum of (Credit * Point) / total of credits \n"
         << endl;
    cout << " CGPA =  Sum of GPA / number of semesters " << endl;
    cout << "-----------------------------------------------------------------\n\n"
         << endl;

    int inmenu;
    cout << "1. Go Back to Main Menu" << endl;
    cout << "2. Exit This App \n\n"
         << endl;
    cout << "Your Input: " << endl;
    cin >> inmenu;

    switch (inmenu)
    {
    case 1:
        break;
    case 2:
        exit(EXIT_SUCCESS);
    default:
        cout << "\n\nYou have Entered Wrong Input!Please Choose Again!" << endl;
        break;
    }
}

int main()
{
    system("cls");
    int input;
    GradeCalculator calculator;

    cout << "--------------------------------------------------------------------------" << endl;
    cout << "                    GPA & CGPA Calculator                                 " << endl;
    cout << "--------------------------------------------------------------------------\n"
         << endl;
    cout << "            MENU:" << endl;
    cout << "                   1. Calculate GPA (Grade Point Average)" << endl;
    cout << "                   2. Calculate CGPA (Cummulative Grade Point Average)" << endl;
    cout << "                   3. Method that is applied here for calculating GPA & CGPA" << endl;
    cout << "                   4. Exit Application" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    cout << "Enter your choice: ";
    cin >> input;

    switch (input)
    {
    case 1:
        calculator.calculateGPA();
        break;
    case 2:
        calculator.calculateCGPA();
        break;
    case 3:
        calculator.method();
        break;
    case 4:
        exit(EXIT_SUCCESS);
    default:
        cout << "You have entered wrong input. Try again!\n"
             << endl;
        break;
    }

    return 0;
}