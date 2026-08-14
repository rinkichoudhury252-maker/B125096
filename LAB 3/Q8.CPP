#include <iostream>
#include <cctype> // For isdigit, isalpha, isblank

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the string array: ";
    cin >> n;

    // 1. Dynamically allocate memory for the character array
    // We allocate n + 1 to accommodate the null terminator '\0'
    char* str = new char[n + 1];

    // Clear the input buffer after reading integer n
    cin.ignore();

    cout << "Enter the string: ";
    // 2. Accept string from user
    // cin.get() reads spaces and stops at newline, filling up to n characters
    cin.get(str, n + 1);

    // Initialize counters
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;

    // 3. Iterate through the dynamically allocated array
    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = str[i];

        if (isalpha(ch)) {
            // Convert to lowercase for easier checking
            char lowerCh = tolower(ch);
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || 
                lowerCh == 'o' || lowerCh == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(ch)) {
            digits++;
        } else if (ch == ' ' || ch == '\t' || ch == '\n') {
            spaces++;
        }
    }

    // Output results
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;

    // 4. Free dynamically allocated memory
    delete[] str;

    return 0;
}   
