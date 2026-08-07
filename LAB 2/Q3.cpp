#include<iostream>
using namespace std;

class temperature{
    int temp;
    public:
    int input(){
        cout<<"enter temperature in celcius: "<<endl;
        cin>>temp;
        return temp;
        
    }
    int farhenheit(){
            return ((9/5)*temp)+32;
        
    }
   
};
int main(){
    temperature c1;
    int celcius= c1.input();
  int a= c1.farhenheit();
  
   cout<<"temperature in celcius:"<<celcius<<endl;
    cout<<"temperature in farhenheit:"<<a<<endl;
    return 0;
}