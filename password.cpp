#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

bool isValidPassword(string password) {
    int len = password.length();

    // Condition (a): Length of the password should be greater than 9 and less than 12
    if (len < 10 || len > 11)
        return false;

    // Condition (b): Password must be started with a digit
    if (!isdigit(password[0]))
        return false;

    // Condition (c): There is a total of 4 alphabets in the user-given password
    int alphabetCount = 0;
    for (char c : password) {
        if (isalpha(c))
            alphabetCount++;
    }
    if (alphabetCount != 4)
        return false;

    // Condition (d): Each alphabet present in the password must be preceded by a lowercase alphabet and succeeded by a digit, or vice versa
    for (int i = 1; i < len - 1; i++) {
        if (isalpha(password[i])) {
            if (!((islower(password[i - 1]) && isdigit(password[i + 1])) || (isdigit(password[i - 1]) && islower(password[i + 1]))))
                return false;
        }
    }

    // Condition (e): Password must be ended with an uppercase alphabet
    if (!isupper(password[len - 1]))
        return false;

    // Condition (f): There is no special character present in the user-given password
    for (char c : password) {
        if (!isalnum(c))
            return false;
    }

    // Condition (g): Ending digit of the user-given password should be an odd number
    if (isdigit(password[len - 2]) && (password[len - 2] - '0') % 2 == 0)
        return false;

    // Condition (h): Second digit of the password should be an even number
    if (isdigit(password[1]) && (password[1] - '0') % 2 != 0)
        return false;

    // Condition (i): There will be no duplicate or redundant value in the user-given password
    sort(password.begin(), password.end());
    for (int i = 1; i < len; i++) {
        if (password[i] == password[i - 1])
            return false;
    }

    // Condition (j): There are at least 2 vowels in the user-given password
    int vowelCount = 0;
    for (char c : password) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vowelCount++;
    }
    if (vowelCount < 2)
        return false;

    return true;
}

int main() {
    string password;
    cout << "Enter the password: ";
    cin >> password;

    if (isValidPassword(password))
        cout << "Valid password" << endl;
    else
        cout << "Invalid password" << endl;

    return 0;
}