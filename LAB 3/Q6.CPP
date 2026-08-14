#include<iostream>
using namespace std;
class product{
   int id;
   string name;
   int qty;
   int price;
   
   public:
   void input(){
    cout<<"enter name of product: "<<endl;
    cin>>name;
    cout<<"enter quantity: "<<endl;
    cin>>qty;
    cout<<"enter price of product: "<<endl;
    cin>> price;
    cout<<"enter id of product: " << endl;
    cin>>id;
   }
   void display(){
    cout<<"total cost of products: "<<price*qty;
   }
int inventory(){
    return price*qty;
}
};
int main(){
    int n,fc;
    cout<<"enter total number of products: "<<endl;
    cin>>n;
    product* p=new product[n];

    for(int i=0;i<n;i++){
        p[i].input();
        p[i].display();
        fc+=p[i].inventory();
    }

    cout<<"total cost in inventory: "<< fc;
    
    delete [] p;
    p=nullptr;
    return 0;
    
}