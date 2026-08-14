#include<iostream>
using namespace std;
class book{
   int id;
   string name;
   string author;
   int price;
   public:
   void input(){
    cout<<"enter name of book: "<<endl;
    cin>>name;
    cout<<"enter name of author: "<<endl;
    cin>>author;
    cout<<"enter price of book: "<<endl;
    cin>> price;
    cout<<"enter id of book: " << endl;
    cin>>id;
   }
   void display(){
    cout<<"book name: "<< name;
    cout<<"author: "<<author;
    cout<<"price: "<< price;
    cout<<"id: "<<id;
   }
};
int main(){
    book* b1=new book;
    b1->input();
    b1->display();
    delete b1;
    b1=nullptr;
    return 0;
}