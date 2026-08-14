#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    // Default constructor
    Employee() : id(0), name(""), salary(0.0) {}

    // Function to accept employee details
    void acceptDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        // Clear input buffer before reading string with spaces
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void displayDetails() const {
        cout << "ID: " << id 
             << ", Name: " << name 
             << ", Salary: $" << salary << endl;
    }

    // Getters for finding highest salary and calculating average
    int getId() const { return id; }
    string getName() const { return name; }
    double getSalary() const { return salary; }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    // Dynamically allocate an array of n Employee objects
    Employee* empArray = new Employee[n];

    // 1. Accept employee details
    for (int i = 0; i < n; ++i) {
        cout << "\n--- Enter details for Employee " << (i + 1) << " ---" << endl;
        empArray[i].acceptDetails();
    }

    // 2. Display all employee details
    cout << "\n--- All Employee Details ---" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Employee " << (i + 1) << ": ";
        empArray[i].displayDetails();
    }

    // 3. Find and display the employee with the highest salary
    if (n > 0) {
        int highestIdx = 0;
        for (int i = 1; i < n; ++i) {
            if (empArray[i].getSalary() > empArray[highestIdx].getSalary()) {
                highestIdx = i;
            }
        }
        cout << "\n--- Employee with Highest Salary ---" << endl;
        cout << "Employee: ";
        empArray[highestIdx].displayDetails();
    }

    // 4. Calculate and display the average salary
    if (n > 0) {
        double totalSalary = 0.0;
        for (int i = 0; i < n; ++i) {
            totalSalary += empArray[i].getSalary();
        }
        double averageSalary = totalSalary / n;
        cout << "\n--- Average Salary ---" << endl;
        cout << "Average Salary: $" << averageSalary << endl;
    } else {
        cout << "\nNo employees to calculate average." << endl;
    }

    // Free dynamically allocated memory
    delete[] empArray;

    return 0;
}   