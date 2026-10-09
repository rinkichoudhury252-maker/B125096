#include <iostream>
using namespace std;

class Temperature {
    double celsius;

public:
    Temperature(double c) : celsius(c) {}

    bool operator>(const Temperature& t) const {
        return celsius > t.celsius;
    }

    bool operator<(const Temperature& t) const {
        return celsius < t.celsius;
    }

    Temperature operator-() const {
        return Temperature(-celsius);
    }

    void display() const {
        cout << celsius << " degree Celsius\n";
    }
};

int main() {
    Temperature t1(35), t2(25);

    cout << "Temperature 1: ";
    t1.display();

    cout << "Temperature 2: ";
    t2.display();

    cout << "t1 > t2: " << (t1 > t2) << endl;
    cout << "t1 < t2: " << (t1 < t2) << endl;

    Temperature t3 = -t1;

    cout << "Negated temperature: ";
    t3.display();

    return 0;
}