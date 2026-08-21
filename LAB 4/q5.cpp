
#include <iostream>
using namespace std;

class EventParticipant {
private:
    string participantName;
    int age;
    string registrationStatus;

public:
    // Constructor
    EventParticipant(string name, int a, string status) {
        participantName = name;
        age = a;
        registrationStatus = status;
    }

    // Friend function declaration
    friend void verifyParticipant(EventParticipant p);
};

void verifyParticipant(EventParticipant p) {
    cout << "----- Event Participant -----" << endl;
    cout << "Name: " << p.participantName << endl;
    cout << "Age: " << p.age << endl;
    cout << "Registration Status: " << p.registrationStatus << endl;

    // Participant must be 18 or older and registration must be active
    if (p.age >= 18 &&( p.registrationStatus == "Active"|| p.registrationStatus == "active"))
        cout << "Result: Eligible" << endl;
    else
        cout << "Result: Not Eligible" << endl;
}

int main() {
    string name;
    int age;
    string status;
    cout<<"enter user name: "<<endl;
    cin>>name;
    cout<<"enter age: "<<endl;
    cin>>age;
    cout<<"enter the status of registration: "<<endl;
    cin>>status;
    EventParticipant p(name,age,status);

    verifyParticipant(p);

    return 0;
}

