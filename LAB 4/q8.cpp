
#include <iostream>
using namespace std;

class ServiceManager;  // Forward declaration

class VehicleService {
private:
    string vehicleNumber;
    string ownerName;
    bool serviceDue;
    int lastServiceKilometres;

public:
    // Constructor
    VehicleService(string number, string owner,
                   bool due, int kilometres) {
        vehicleNumber = number;
        ownerName = owner;
        serviceDue = due;
        lastServiceKilometres = kilometres;
    }

    // Declare ServiceManager as friend class
    friend class ServiceManager;
};

class ServiceManager {
public:

    // Display vehicle service information
    void displayInfo(VehicleService &v) {
        cout << "----- Vehicle Service Information -----" << endl;
        cout << "Vehicle Number: " << v.vehicleNumber << endl;
        cout << "Owner Name: " << v.ownerName << endl;
        cout << "Last Service: "
             << v.lastServiceKilometres << " km" << endl;
        cout << "Service Due: "
             << (v.serviceDue ? "Yes" : "No") << endl;
    }

    // Mark service as completed
    void completeService(VehicleService &v) {
        v.serviceDue = false;
        cout << "Service marked as completed." << endl;
    }

    // Update last service kilometres
    void updateKilometres(VehicleService &v, int km) {
        v.lastServiceKilometres = km;
        cout << "Last service kilometres updated." << endl;
    }

    // Check whether service is required
    void checkService(VehicleService &v) {
        if (v.serviceDue)
            cout << "Vehicle requires servicing." << endl;
        else
            cout << "Vehicle does not require servicing." << endl;
    }
};

int main() {
    VehicleService v("OD02AB1234", "Rinki", true, 15000);
    ServiceManager manager;

    manager.displayInfo(v);
    manager.checkService(v);

    manager.completeService(v);
    manager.updateKilometres(v, 16000);

    manager.displayInfo(v);

    return 0;
}

