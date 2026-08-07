#include<iostream>
using namespace std;

class hostelfee{
   char name[50];
   int id;
   int fee;
   int months;
   bool isdelayed;
   int totalfees;
   public:
   void input(){
        cout<<"enter  name: "<<endl;
        cin>>name;
        cout<<"enter id: "<< endl;
        cin>>id;
        cout<<"enter monthly fee: "<<endl;
        cin>>fee;
        cout<<"enter number of months: "<<endl;
        cin>>months;

        char delaychoice;
        cout<<"is the payment delayed(y/n): "<< endl;
        cin>> delaychoice;
        if(delaychoice=='y'|| delaychoice=='Y'){
            isdelayed=true;
        }
    }
    void Fee(){
         totalfees=fee*months;
    }
    void latefine(){
         if(isdelayed){
            totalfees+=500;
         }
    }


    void displayFinalAmount() {
        cout << "\n--- Hostel Fee Receipt ---" << endl;
        cout << "Student Name: " << name << endl;
        cout << "Hostel ID   : " << id << endl;
        cout << "Monthly Fee : ₹" << fee << endl;
        cout << "Months Paid : " << months << endl;
        cout << "Late Fine   : " << (isdelayed ? "₹500 applied" : "None") << endl;
        cout << "--------------------------" << endl;
        cout << "Total Payable: ₹" << totalfees<< endl;
    }
};

int main() {
    // Create an object of HostelFee class
    hostelfee student;

    // Execute member functions in logical order
    student.input();
    student.Fee();
    student.latefine();
    student.displayFinalAmount();

    return 0;
}
