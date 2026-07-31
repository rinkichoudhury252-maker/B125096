#include <iostream>
#include <vector>
#include <limits> // For numeric_limits

using namespace std;

int main() {
    int N;

    // Prompt for number of elements
    cout << "Enter the number of integers (N): ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Invalid input. N must be a positive integer.\n";
        return 1;
    }

    vector<int> arr(N); // Dynamic array to store integers

    // Input N integers with validation
    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; ++i) {
        while (!(cin >> arr[i])) {
            cerr << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // Display elements in reverse order
    cout << "Array elements in reverse order:\n";
    for (int i = N - 1; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}