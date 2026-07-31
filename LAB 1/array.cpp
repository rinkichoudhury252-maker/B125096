//displaying largest element of an array
#include<iostream>
using namespace std;
int main(){
    int n,i,max,temp;
    cout<<"enter length of element: \n";
    cin>>n ;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    max=arr[0];
for(i=1;i<n;i++){
  if(arr[i]>max){
  
   temp=arr[i];
   arr[i]=max;
   max=temp;
  }
}
cout<<"largest number is :"<<max<<"\n";
return 0;
}