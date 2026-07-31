#include<iostream>
#include<iomanip>
using namespace std;
struct student{
    int rollno;
    string name;
    float marks;

};
int main(){
    student s[5];
    int end1;
    cout<<"enter details of 5 stuedent:\n";
    for(int i=0;i<5;i++){
        cout<<"\nstudent"<<i+1<<end1;
        cout<<"enter roll number:\n";
        cin>>s[i].rollno;
        cin.ignore();
        cout<<"enter name:";
        getline(cin,s[i].name);

        cout<<"enter marks";
        cin>>s[i].marks;}

        cout<<
    "-------------------------------------------------------------------------\n";
    cout<<left<<setw(10)<<"rollno"
          <<setw(20)<<"name"
          <<setw(10)<<"marks"<<
          end1;
          cout<<
    " --------------------------------------------------------------------------\n";
    for(int i=0;i<5;i++){
  cout<<left<<setw(10)<<
  s[i].rollno
       <<setw(20)<<s[i].name
       <<setw(10)<<fixed<<
       end1;
    }
   cout <<
   "--------------------------------------------------------------------------------\n";
   return 0;
    }

