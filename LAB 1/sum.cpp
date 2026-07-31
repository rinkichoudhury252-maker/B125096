#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"enter length of element: \n";
    cin>>n ;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    int*ptr=arr;
    for(i=0;i<n;i++){
        sum+=*ptr;
        ptr++;
}
cout<<"sum of elements"<<sum;
return 0;
}
