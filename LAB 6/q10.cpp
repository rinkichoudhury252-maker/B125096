#include <iostream>
using namespace std;

class Bill {
    int items;
    double amount;

public:
    Bill(int i, double a) : items(i), amount(a) {}

    Bill operator+(const Bill& b) const {
        return Bill(items + b.items,
                    amount + b.amount);
    }

    bool operator>(const Bill& b) const {
        return amount > b.amount;
    }

    void display() const {
        cout << "Number of items: " << items
             << "\nTotal amount: Rs. " << amount << endl;
    }
};

int main() {
    Bill b1(3, 500);
    Bill b2(2, 300);

    cout << "First Bill:\n";
    b1.display();

    cout << "\nSecond Bill:\n";
    b2.display();

    Bill b3 = b1 + b2;

    cout << "\nCombined Bill:\n";
    b3.display();

    cout << "\nFirst bill > Second bill: "
         << (b1 > b2) << endl;

    return 0;
}