#include<iostream>
using namespace std;

class time{
  int h1, m1,h2,m2;
  public:
  void values(){
    cout<<"enter hour for first time: "<< endl;
    cin>>h1;
    cout<<"enter hour for second time: "<< endl;
    cin>>h2;
    cout<<"enter minutes for first time: "<< endl;
    cin>>m1;
     cout<<"enter minutes for second time: "<< endl;
    cin>>m2;
  }
  void add(){
    int totalminutes=m1+m2;
    int totalhours=h1+h2;
  }
  void display(){
    if((m1+m2)<60){
        cout<<"total time: "<<h1+h1<<":"<<m1+m2<<endl;
    }else{
      int extrahour=(m1+m2)/60;
      int totalhour=h1+h2+extrahour;
      int minute=(m1+m2)%60;
      cout<<"total time: "<<totalhour<<":"<<minute<<endl;
    }
  }};
  int main(){
    time t1;
    t1.values();
    t1.add();
    t1.display();
    return 0;
  }