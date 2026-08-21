
#include <iostream>
using namespace std;

class PrinterManager;  // Forward declaration

class Printer {
private:
    string printerName;
    int pagesPrinted;
    int inkLevel;
    bool powerStatus;

public:
    // Constructor
    Printer(string name, int pages, int ink, bool power) {
        printerName = name;
        pagesPrinted = pages;
        inkLevel = ink;
        powerStatus = power;
    }

    // Declare PrinterManager as friend class
    friend class PrinterManager;
};

class PrinterManager {
public:

    // Display printer information
    void displayInfo(Printer &p) {
        cout << "----- Printer Information -----" << endl;
        cout << "Printer Name: " << p.printerName << endl;
        cout << "Pages Printed: " << p.pagesPrinted << endl;
        cout << "Ink Level: " << p.inkLevel << "%" << endl;
        cout << "Power: " << (p.powerStatus ? "ON" : "OFF") << endl;
    }

    // Turn printer ON
    void turnOn(Printer &p) {
        p.powerStatus = true;
        cout << "Printer turned ON." << endl;
    }

    // Turn printer OFF
    void turnOff(Printer &p) {
        p.powerStatus = false;
        cout << "Printer turned OFF." << endl;
    }

    // Check ink level
    void checkInk(Printer &p) {
        cout << "Ink Level: " << p.inkLevel << "%" << endl;
    }

    // Reset page count
    void resetPageCount(Printer &p) {
        p.pagesPrinted = 0;
        cout << "Page count reset successfully." << endl;
    }
};

int main() {
    string name;
    int pages;
    int ink;
    bool status;
    cout<<"enter printer name: "<<endl;
    cin>>name;
    cout<<"enter number of pages printed: "<<endl;
    cin>>pages;
    cout<<"enter ink level: "<<endl;
    cin>>ink;
    cout<<"enter power status: "<<endl;
    cin>>status;
    Printer p(name,pages,ink,status);
    PrinterManager manager;

    manager.displayInfo(p);

    manager.turnOn(p);
    manager.checkInk(p);
    manager.resetPageCount(p);

    manager.displayInfo(p);

    manager.turnOff(p);

    return 0;
}

