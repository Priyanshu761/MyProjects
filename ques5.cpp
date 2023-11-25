// Making a Digital Clock

#include <iostream>
#include <iomanip>
using namespace std;

class DigitalClock
{
private:
    int hours, minutes, seconds;

public:
    DigitalClock(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void displayTime()
    {
        cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << " ";

        if (hours >= 12)
        {
            cout << "PM";
        }
        else
        {
            cout << "AM";
        }
    }
};
int main()
{
    int hours, minutes, seconds;
    cout << "Enter hours : " << endl;
    cin >> hours;
    cout << "Enter minutes : " << endl;
    cin >> minutes;
    cout << "Enter seconds : " << endl;
    cin >> seconds;

    DigitalClock clock(hours, minutes, seconds);
    clock.displayTime();
    return 0;
}