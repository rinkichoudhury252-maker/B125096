#include <iostream>
using namespace std;

class InventoryItem {
    int productID, quantity;
    double price;

public:
    InventoryItem(int id, double p, int q)
        : productID(id), price(p), quantity(q) {}

    InventoryItem operator+(const InventoryItem& item) const {
        if (productID != item.productID || price != item.price) {
            cout << "Incompatible inventory items\n";
            return *this;
        }

        return InventoryItem(productID, price,
                             quantity + item.quantity);
    }

    void display() const {
        cout << "Product ID: " << productID
             << ", Price: " << price
             << ", Quantity: " << quantity << endl;
    }
};

int main() {
    InventoryItem i1(101, 50.0, 10);
    InventoryItem i2(101, 50.0, 5);

    cout << "First item: ";
    i1.display();

    cout << "Second item: ";
    i2.display();

    InventoryItem i3 = i1 + i2;

    cout << "Combined item: ";
    i3.display();

    return 0;
}