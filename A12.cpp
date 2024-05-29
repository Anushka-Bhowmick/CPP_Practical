#include <iostream>
#include <cstdlib>  For atoi
#include <climits>  For INT_MIN
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide at least one number as a command line argument." << endl;
        return 1;
    }

    int largest = INT_MIN;

    for (int i = 1; i < argc; ++i) {
        int num = atoi(argv[i]);
        if (num > largest) {
            largest = num;
        }
    }

    cout << "The largest number is: " << largest << endl;
    return 0;
}
