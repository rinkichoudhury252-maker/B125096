#include<iostream>
using namespace std;
int main(){
    int n,i,key,found=0;
    cout<<"enter length of element: \n";
    cin>>n ;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
cout<<"enter the element to search: "<<"\n";
cin>>key;
  for(i=0;i<n;i++){
    if(arr[i]==key){
        cout<<"element found at"<<i<<"position"<<"\n";
        found=1;
    }
}
if(found==0){
 cout<<"element not found"<<"\n";

}
}