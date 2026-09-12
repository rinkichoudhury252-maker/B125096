#include <iostream>
using namespace std;

class Trip
{
private:
    int tripID;
    float distance;
    float baseFare;
    float finalFare;

public:
    
    Trip(int id, float dist, float base)
    {
        tripID = id;
        distance = dist;
        baseFare = base;
        finalFare = 0;
    }

   
    float fare()
    {
        finalFare = baseFare + (distance * 10);
        return finalFare;
    }

    float fare(int waitingTime)
    {
        finalFare = baseFare + (distance * 10)
                    + (waitingTime * 2);

        return finalFare;
    }

    float fare(int waitingTime, int discount)
    {
        float fareWithWaiting;

        fareWithWaiting = baseFare + (distance * 10)
                          + (waitingTime * 2);

        finalFare = fareWithWaiting
                    - (fareWithWaiting * discount / 100);

        return finalFare;
    }

    void display()
    {
        cout << "Trip ID: " << tripID << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Base Fare: Rs. " << baseFare << endl;
        cout << "Final Fare: Rs. " << finalFare << endl;
    }

    friend void compareFare(Trip &, Trip &);
};


void compareFare(Trip &t1, Trip &t2)
{
    if (t1.finalFare < t2.finalFare)
    {
        cout << "\nTrip " << t1.tripID
             << " is cheaper." << endl;

        cout << "Fare: Rs. " << t1.finalFare << endl;
    }
    else if (t2.finalFare < t1.finalFare)
    {
        cout << "\nTrip " << t2.tripID
             << " is cheaper." << endl;

        cout << "Fare: Rs. " << t2.finalFare << endl;
    }
    else
    {
        cout << "\nBoth trips have the same fare: Rs. "
             << t1.finalFare << endl;
    }
}

int main()
{
    int id1, id2;
    float distance1, distance2;
    float base1, base2;

    cout << "Enter Trip 1 ID: ";
    cin >> id1;

    cout << "Enter Trip 1 distance: ";
    cin >> distance1;

    cout << "Enter Trip 1 base fare: ";
    cin >> base1;

    cout << "\nEnter Trip 2 ID: ";
    cin >> id2;

    cout << "Enter Trip 2 distance: ";
    cin >> distance2;

    cout << "Enter Trip 2 base fare: ";
    cin >> base2;

  
    Trip *trip1 = new Trip(id1, distance1, base1);
    Trip *trip2 = new Trip(id2, distance2, base2);

    
    trip1->fare();

    int waitingTime, discount;

    cout << "\nEnter waiting time for Trip 2: ";
    cin >> waitingTime;

    cout << "Enter discount percentage: ";
    cin >> discount;

    trip2->fare(waitingTime, discount);

   
    cout << "\n--- Trip 1 ---\n";
    trip1->display();

    cout << "\n--- Trip 2 ---\n";
    trip2->display();

    compareFare(*trip1, *trip2);

    
    delete trip1;
    delete trip2;

    return 0;
}