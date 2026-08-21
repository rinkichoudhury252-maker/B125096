
#include <iostream>
using namespace std;

class ElectricMeter {
private:
    int meterNumber;
    string consumerName;
    int unitsConsumed;

public:
    // Constructor
    ElectricMeter(int meter, string name, int units) {
        meterNumber = meter;
        consumerName = name;
        unitsConsumed = units;
    }

    // Friend function declaration
    friend void checkUsage(ElectricMeter e);
};

void checkUsage(ElectricMeter e) {
    cout << "----- Electricity Usage -----" << endl;
    cout << "Meter Number: " << e.meterNumber << endl;
    cout << "Consumer Name: " << e.consumerName << endl;
    cout << "Units Consumed: " << e.unitsConsumed << endl;

    // Categorize electricity usage
    if (e.unitsConsumed < 100)
        cout << "Usage Category: Low Usage" << endl;
    else if (e.unitsConsumed <= 300)
        cout << "Usage Category: Moderate Usage" << endl;
    else
        cout << "Usage Category: High Usage" << endl;
}

int main() {
    ElectricMeter e(1001, "Rinki", 250);

    checkUsage(e);

    return 0;
}
