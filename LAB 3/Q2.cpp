#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the length of array: "<<endl;
    cin>>n;
    int*arr= new int[n];
    cout<<"enter elemnts of  array: "<<endl;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    cout<<"array in reverse order: "<< endl;
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<endl;
    }
    delete[] arr;
    arr=nullptr;
    return 0;
}