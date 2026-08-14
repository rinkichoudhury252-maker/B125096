#include<iostream>
using namespace std;
int main(){
    int n,ceven=0,codd=0;
    cout<<"enter the length of array: "<<endl;
    cin>>n;
    int*arr= new int[n];
    cout<<"enter elemnts of  array: "<<endl;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            ceven+=1;
        }else{
            codd+=1;
        }
    }
    cout<<"total number of odd integers: "<< codd<< endl;
    cout<<"total number of even integers: "<< ceven<<endl;
    delete[] arr;
    arr=nullptr;
    return 0;
}