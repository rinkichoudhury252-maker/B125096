#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll;
    float marks;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n];
    float totalMarks = 0;
    int topIndex = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore(); // clear buffer
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].roll;
        cout << "Marks: ";
        cin >> students[i].marks;

        totalMarks += students[i].marks;

        if (students[i].marks > students[topIndex].marks) {
            topIndex = i;
        }
    }

    float average = totalMarks / n;

    cout << "\n--- Student with Highest Marks ---\n";
    cout << "Name: " << students[topIndex].name << "\n";
    cout << "Roll: " << students[topIndex].roll << "\n";
    cout << "Marks: " << students[topIndex].marks << "\n";

    cout << "\nAverage Marks of Class: " << average << endl;

    return 0;
}
