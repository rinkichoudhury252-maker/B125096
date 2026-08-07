#include <iostream>
#include <string>
#include <iomanip> // for formatting output
using namespace std;

class WaterBill {
private:
    int consumerNumber;
    string consumerName;
    double waterConsumption; // in litres
    double billAmount;

    // Helper function to calculate bill based on slab rates
    void calculateBill() {
        billAmount = 0.0;
        double remaining = waterConsumption;

        // First 500 litres @ ₹2 per litre
        if (remaining > 0) {
            double slab = min(remaining, 500.0);
            billAmount += slab * 2;
            remaining -= slab;
        }

        // Next 500 litres @ ₹3 per litre
        if (remaining > 0) {
            double slab = min(remaining, 500.0);
            billAmount += slab * 3;
            remaining -= slab;
        }

        // Above 1000 litres @ ₹5 per litre
        if (remaining > 0) {
            billAmount += remaining * 5;
        }
    }

public:
    // Function to accept consumer details
    void acceptDetails() {
        cout << "Enter Consumer Number: ";
        while (!(cin >> consumerNumber) || consumerNumber <= 0) {
            cout << "Invalid input. Enter a positive integer: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cin.ignore(); // clear newline from buffer
        cout << "Enter Consumer Name: ";
        getline(cin, consumerName);

        cout << "Enter Water Consumption (in litres): ";
        while (!(cin >> waterConsumption) || waterConsumption < 0) {
            cout << "Invalid input. Enter a non-negative number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        calculateBill(); // Calculate bill after input
    }

    // Function to display the bill
    void displayBill() const {
        cout << "\n----- Water Bill -----\n";
        cout << "Consumer Number : " << consumerNumber << "\n";
        cout << "Consumer Name   : " << consumerName << "\n";
        cout << "Consumption     : " << waterConsumption << " litres\n";
        cout << "Bill Amount     : ₹" << fixed << setprecision(2) << billAmount << "\n";
        cout << "----------------------\n";
    }
};

int main() {
    WaterBill wb;
    wb.acceptDetails();
    wb.displayBill();
    return 0;
}
