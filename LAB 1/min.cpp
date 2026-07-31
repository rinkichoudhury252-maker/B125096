#include<iostream>
using namespace std;
int main(){
    int n,i,min,temp;
    cout<<"enter length of element: \n";
    cin>>n ;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    min=arr[0];
for(i=1;i<n;i++){
  if(min>arr[i]){
  
   temp=arr[i];
   arr[i]=min;
   min=temp;
  }
}
cout<<"smallest number is :"<<min<<"\n";
return 0;
}


 