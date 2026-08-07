#include<iostream>
using namespace std;

class square{
    int side;
    public:
    void acceptinput(){
        cout<<"enter length of side:"<<endl;
        cin>>side;
    }
    int area(){
        int Area=side*side;
        return Area;
    }
    int perimeter(){
        int pm=4*(side);
        return pm;
    }
};
int main(){
    square r;
    r.acceptinput();
  int AREA= r.area();
   int PERIMETER= r.perimeter();
   cout<<"area is : "<<AREA<< endl;
   cout<<"perimeter is: "<<PERIMETER<<endl;
   return 0;
}