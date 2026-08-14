#include<iostream>
using namespace std;
void input(int* arr[],int n){
    cout<<"enter elemnts of  array: ";
    for(int i=0;i<n;i++){
      cin >> *(arr[i]);
    }
}

void sum(int* arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=*arr[i];
    }
    cout<<"sum of all elements: "<< sum << endl;
}
void small_element(int*arr[],int n){
    int temp,min=*arr[0];
     for(int i=1;i<n;i++){
       if(*arr[0]>*arr[i]){
       temp=*arr[i];
       *arr[i]= min;
       min=temp;
       }
     }
     cout<<"smallest element is: "<<min<<endl;
}
void large_element(int* arr[],int n){
int temp,max=*arr[0];
     for(int i=1;i<n;i++){
       if(arr[0]<arr[i]){
       temp=*arr[i];
       *arr[i]=max;
       max=temp;
       }
     }
     cout<<"largeest element is: "<<max<<endl;
}

int main(){
   int n;
    cout<<"enter the length of array: ";
    cin >> n; 

    int *arr=new int[n];
    input(&arr,n);
    sum(&arr,n);
    small_element(&arr,n);
    large_element(&arr,n);
    return 0;
}
