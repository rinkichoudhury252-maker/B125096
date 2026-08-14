#include<iostream>
using namespace std;
int main(){
    int n,key,found=0;
    cout<<"enter the length of array: "<<endl;
    cin>>n;
    int*arr= new int[n];
    cout<<"enter elemnts of  array: "<<endl;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    cout<<"enter the element to search: "<<endl;
    cin>>key;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"element found at "<< i+1<< " position"<< endl;
            found+=1;
        }
    }
    if(found==0){
        cout<<"element not found"<<endl;
    }
    delete[] arr;
    arr = nullptr;
    return 0;
}
