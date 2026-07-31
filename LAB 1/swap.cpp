#include<iostream>
using namespace std;
void swap(int*x,int*y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main(){
    int n1, n2;
    cout<<"enter number 1:";
    cin>>n1;
    cout<<"enter num2";
    cin>>n2;
    cout<<"before swapping num1="<<n1<<"and num2="<<n2;
    swap(&n1,&n2);
     cout<<"after swapping num1="<<n1<<"and num2="<<n2;
     return 0;
}