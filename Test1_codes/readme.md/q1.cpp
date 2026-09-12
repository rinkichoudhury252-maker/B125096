#include <iostream>
using namespace std;

class ParkingFloor
{
private:
    int floorNumber;
    int numberOfSlots;
    bool *slotOccupied;

public:
  
    ParkingFloor(int floor, int slots)
    {
        floorNumber = floor;
        numberOfSlots = slots;

        slotOccupied = new bool[numberOfSlots];

        for (int i = 0; i < numberOfSlots; i++)
        {
            slotOccupied[i] = false;
        }
    }

    void reserve(int slot)
    {
        if (slot < 1 || slot > numberOfSlots)
        {
            cout << "Invalid slot number!" << endl;
        }
        else if (slotOccupied[slot - 1])
        {
            cout << "Slot " << slot << " is already occupied." << endl;
        }
        else
        {
            slotOccupied[slot - 1] = true;
            cout << "Slot " << slot << " reserved successfully." << endl;
        }
    }

    
    void reserve(int startSlot, int count)
    {
        if (startSlot < 1 || startSlot + count - 1 > numberOfSlots)
        {
            cout << "Invalid slot range!" << endl;
            return;
        }

       
        for (int i = startSlot - 1; i < startSlot - 1 + count; i++)
        {
            if (slotOccupied[i])
            {
                cout << "Reservation failed. Slot "
                     << i + 1 << " is already occupied." << endl;
                return;
            }
        }

        
        for (int i = startSlot - 1; i < startSlot - 1 + count; i++)
        {
            slotOccupied[i] = true;
        }

        cout << count << " consecutive slots reserved successfully."
             << endl;
    }

  
    void display()
    {
        cout << "\nFloor " << floorNumber << ": ";

        for (int i = 0; i < numberOfSlots; i++)
        {
            if (slotOccupied[i])
                cout << "[X] ";
            else
                cout << "[ ] ";
        }

        cout << endl;
    }

   
    ~ParkingFloor()
    {
        delete[] slotOccupied;
    }
};

int main()
{
    int numberOfFloors;

    cout << "Enter number of floors: ";
    cin >> numberOfFloors;

    ParkingFloor **floors = new ParkingFloor *[numberOfFloors];

    for (int i = 0; i < numberOfFloors; i++)
    {
        int slots;

        cout << "Enter number of slots for floor "
             << i + 1 << ": ";
        cin >> slots;

        floors[i] = new ParkingFloor(i + 1, slots);
    }

   
    cout << "\n--- Reservations ---\n";

    floors[0]->reserve(2);       
    floors[0]->reserve(4, 3);    

    if (numberOfFloors > 1)
    {
        floors[1]->reserve(1);
        floors[1]->reserve(3, 2);
    }

    
    cout << "\n--- Parking Status ---\n";

    for (int i = 0; i < numberOfFloors; i++)
    {
        floors[i]->display();
    }

    
    for (int i = 0; i < numberOfFloors; i++)
    {
        delete floors[i];
    }

    delete[] floors;

    return 0;
}