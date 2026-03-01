#include <iostream>
using namespace std;

bool palindrome(string str, int start, int end) {
    // Base condition
    if (start >= end)
        return true;

    // If characters are not same
    if (str[start] != str[end])
        return false;

    // Recursive call
    return palindrome(str, start + 1, end - 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (palindrome(str, 0, str.length() - 1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}