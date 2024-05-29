#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void initialize(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void display() const {
        cout << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    Time add(const Time& t) const {
        int totalSeconds = (hours + t.hours) * 3600 + (minutes + t.minutes) * 60 + (seconds + t.seconds);
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }

    Time subtract(const Time& t) const {
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int totalSeconds = totalSeconds1 - totalSeconds2;

        if (totalSeconds < 0) totalSeconds = 0;  
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }
};

int main() {
    int h, m, s;

    cout << "Enter hours for Time 1: ";
    cin >> h;
    cout << "Enter minutes for Time 1: ";
    cin >> m;
    cout << "Enter seconds for Time 1: ";
    cin >> s;
    Time t1(h, m, s);

    cout << "Enter hours for Time 2: ";
    cin >> h;
    cout << "Enter minutes for Time 2: ";
    cin >> m;
    cout << "Enter seconds for Time 2: ";
    cin >> s;
    Time t2(h, m, s);

    cout << "Time 1: ";
    t1.display();
    cout << "Time 2: ";
    t2.display();

    Time t3 = t1.add(t2);
    cout << "Sum of Time 1 and Time 2: ";
    t3.display();

    Time t4 = t1.subtract(t2);
    cout << "Difference of Time 1 and Time 2: ";
    t4.display();

    return 0;
}
