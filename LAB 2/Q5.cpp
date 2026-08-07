#include<iostream>
using namespace std;

class mobileRecharge{
    public:
    int mob;
    int name;
    int curr_balan;
    int recharge;


    void input(){
        cout<<"enter name: "<<endl;
        cin>>name;
        cout<<"enter mobile number"<< endl;
        cin>>mob;
        cout<<"enter current balance: "<<endl;
        cin>>curr_balan;
    }
    void Recharge(){
        
        cout<<"enter recharge amount but make sure that recharge is less than balance: "<<endl;
        cin>>recharge;
    }
    int updated(){
        return curr_balan-recharge;
    }
    void display(){
        cout<<"  name:"<<name<<endl;
    cout<<"mobile number:"<<mob<<endl;
    cout<<"balance:"<<curr_balan<<endl;
    cout<<"updated balance:"<<curr_balan-recharge<<endl;
    }
};
int main(){
    mobileRecharge m1;
    m1.input();
    m1.Recharge();
    m1.updated();
    m1.display();

  return 0;
}