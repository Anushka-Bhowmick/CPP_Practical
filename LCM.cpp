#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

string numToWords(int num) {
    string ones[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                     "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (num < 20) {
        return ones[num];
    } else {
        return tens[num / 10] + ((num % 10 != 0) ? " " + ones[num % 10] : "");
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool validateInput(int num) {
    if (num <= 0 || num > 100)
        return false;
    string numStr = to_string(num);
    for (char c : numStr) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool validatePrimes(int a, int b) {
    return (isPrime(a) && isPrime(b) && a != b);
}

bool validateDifferent(int a, int b) {
    return a != b;
}

bool hasLowerCase(const string& str) {
    for (char c : str) {
        if (islower(c))
            return true;
    }
    return false;
}

bool hasUpperCase(const string& str) {
    for (char c : str) {
        if (isupper(c))
            return true;
    }
    return false;
}

void testCasePositive(int num1, int num2) {
    if (validateInput(num1) && validateInput(num2) && !hasLowerCase(to_string(num1)) && !hasLowerCase(to_string(num2))) {
        if (validatePrimes(num1, num2)) {
            if (validateDifferent(num1, num2)) {
                cout << "Test Case Positive: All conditions met!" << endl;
                cout << "Input numbers in words: " << numToWords(num1) << " and " << numToWords(num2) << endl;
                cout << "LCM of " << num1 << " and " << num2 << " is " << lcm(num1, num2) << endl;
            } else {
                cout << "Test Case Failed: Numbers are not different." << endl;
            }
        } else {
            cout << "Test Case Failed: At least one of the numbers is not prime." << endl;
        }
    } else {
        cout << "Test Case Failed: Numbers should be positive integers within the range of 1 to 100 and should not contain any lowercase or uppercase characters." << endl;
    }
}

int main() {
    int num1, num2;

    cout << "Enter two different prime integers: ";
    cin >> num1 >> num2;

    testCasePositive(num1, num2);

    return 0;
}
