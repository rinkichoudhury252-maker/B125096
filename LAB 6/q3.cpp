#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    double price;

public:
    Book(string t, double p) : title(t), price(p) {}

    bool operator<(const Book& b) const {
        if (price == b.price)
            return title < b.title;

        return price < b.price;
    }

    void display() const {
        cout << title << " - Rs. " << price << endl;
    }
};

int main() {
    Book b1("Atomic Habits", 350);
    Book b2("Deep Work", 400);
    Book b3("Ikigai", 350);

    b1.display();
    b2.display();

    cout << "Book 1 < Book 2: "
         << (b1 < b2 ? "True" : "False") << endl;

    cout << "Book 1 < Book 3: "
         << (b1 < b3 ? "True" : "False") << endl;

    return 0;
}