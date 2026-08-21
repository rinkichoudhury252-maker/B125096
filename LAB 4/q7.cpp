
#include <iostream>
using namespace std;

class MuseumManager;  // Forward declaration

class Exhibit {
private:
    string exhibitName;
    int exhibitID;
    int visitorCount;
    bool displayStatus;

public:
    // Constructor
    Exhibit(string name, int id, int visitors, bool status) {
        exhibitName = name;
        exhibitID = id;
        visitorCount = visitors;
        displayStatus = status;
    }

    // Declare MuseumManager as friend class
    friend class MuseumManager;
};

class MuseumManager {
public:

    // Display exhibit information
    void displayInfo(Exhibit &e) {
        cout << "----- Exhibit Information -----" << endl;
        cout << "Exhibit Name: " << e.exhibitName << endl;
        cout << "Exhibit ID: " << e.exhibitID << endl;
        cout << "Visitor Count: " << e.visitorCount << endl;
        cout << "Display Status: "
             << (e.displayStatus ? "Open" : "Closed") << endl;
    }

    // Add visitors
    void addVisitors(Exhibit &e, int count) {
        e.visitorCount += count;
        cout << count << " visitors added." << endl;
    }

    // Reset visitor count
    void resetVisitors(Exhibit &e) {
        e.visitorCount = 0;
        cout << "Visitor count reset." << endl;
    }

    // Open exhibit
    void openExhibit(Exhibit &e) {
        e.displayStatus = true;
        cout << "Exhibit opened." << endl;
    }

    // Close exhibit
    void closeExhibit(Exhibit &e) {
        e.displayStatus = false;
        cout << "Exhibit closed." << endl;
    }

    // Display current status
    void displayStatus(Exhibit &e) {
        cout << "Exhibit is currently "
             << (e.displayStatus ? "OPEN" : "CLOSED") << endl;
    }
};

int main() {
    Exhibit e("Ancient Sculpture", 101, 50, true);
    MuseumManager manager;

    manager.displayInfo(e);
    manager.addVisitors(e, 20);
    manager.displayStatus(e);
    manager.closeExhibit(e);
    manager.displayInfo(e);

    return 0;
}
