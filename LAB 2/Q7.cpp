#include<iostream>
using namespace std;

class movieticket{
   char moviename[50];
   int ticketprice;
   int numofticket;
   public:
   void input(){
        cout<<"enter movie name: "<<endl;
        cin>>moviename;
        cout<<"enter ticket price: "<< endl;
        cin>>ticketprice;
        cout<<"enter number of ticket: "<<endl;
        cin>>numofticket;
    }
    void cost(){
        int ticketcost=ticketprice*numofticket;
    }
    void details(){
        cout<<" movie name:"<<moviename<<endl;
    cout<<"ticket price:"<<ticketprice<<endl;
    cout<<"number of tickets:"<<numofticket<<endl;
    cout<<"total cost:"<<numofticket*ticketprice<<endl;
    }
};
int main(){
    movieticket m1;
    m1.input();
    m1.cost();
    m1.details();
    return 0;

}