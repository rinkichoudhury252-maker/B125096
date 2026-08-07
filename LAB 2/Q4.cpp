#include<iostream>
using namespace std;

class hotelroom{
   int roomnum;
   char guestname[50];
   int days;
   int cost;
   public:
   void input(){
   cout<<"enter guest name:"<<endl;
    cin>>guestname;
    cout<<"enter days stayed:"<<endl;
    cin>>days;
    cout<<"enter room number:"<<endl;
    cin>>roomnum;
    cout<<"enter cost per day:"<<endl;
    cin>>cost;
   }
int rent(){
    int totalrent= days*cost;
   }
   void display(){
    cout<<" guest name:"<<guestname;
    cout<<"number of days stayed:"<<days;
    cout<<"total rent:"<<days*cost;
    cout<<"room number:"<<roomnum;

   }
};
int main(){
    hotelroom s1;
    s1.input();
    int totallrent=s1.rent();
    s1.display();
    return 0;
}