#include<iostream>
using namespace std;
int main(){
    int n,i,avg=0;
    cout<<"enter length of element: \n";
    cin>>n ;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
      avg+=arr[i];

}
     avg=avg/n;
     cout<<"average is:"<<avg<<"\n";
     return 0;
}