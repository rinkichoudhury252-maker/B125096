#include<iostream>
using namespace std;

class car{
    int carnum;
    char name[30];
    int year;
    public:

    void input_details(){
        cout<<"enter carnumber: "<<endl;
        cin>>carnum;
        cout<<"enter name: "<<endl;
        cin>>name;
        cout<<"enter model year: "<<endl;
        cin>>year;
    }
    void output_details(){
        cout<<"roll number is: "<<carnum<<endl;
        cout<<"name is: "<<name<<endl;
        cout<<"mark is: "<<year<<endl;
    }
};
int main(){
  car s1;
  s1.input_details();
  s1.output_details();
  return 0;
}