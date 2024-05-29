#include <iostream>
#include <cstdlib>  
#include <stdexcept>  
using namespace std;

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            throw invalid_argument("Exactly two arguments are required.");
        }

        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);

        if (argv[1] == string("0") || num1 != 0) {
             //num1 is valid
        } else {
            throw invalid_argument("First argument must be a number.");
        }

        if (argv[2] == string("0") || num2 != 0) {
            // num2 is valid
        } else {
            throw invalid_argument("Second argument must be a number.");
        }

        if (num2 == 0) {
            throw runtime_error("Division by zero error.");
        }

        double result = static_cast<double>(num1) / num2;
        cout << "The result of division is: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << "Invalid argument: " << e.what() << endl;
        return 1;
    } catch (const runtime_error& e) {
        cout << "Runtime error: " << e.what() << endl;
        return 1;
    } catch (...) {
        cout << "An unknown error occurred." << endl;
        return 1;
    }

    return 0;
}
