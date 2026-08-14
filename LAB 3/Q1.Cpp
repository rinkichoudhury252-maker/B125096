#include<iostream>
using namespace std;
int main(){
    int n1,n2,sum,diff,multiply;
    float div;
    cout<<"enter n1: "<<endl;
    cin>>n1;
    cout<<"enter n2: "<<endl;
    cin>>n2;
    int* p=new int(n1);
     int*q=new int(n2);
     cout<<n1<<"+"<<n2<<"="<<n1+n2;
     cout<<n1<<"-"<<n2<<"="<<n1-n2;
     cout<<n1<<"*"<<n2<<"="<<n1*n2;
     if(n2!=0){
     cout<<n1<<"/"<<n2<<"="<<n1/n2;}
     delete p;
     p=nullptr;
     return 0;
     delete q;
     q=nullptr;
}