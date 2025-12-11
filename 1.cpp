#include<iostream>
#include<string.h>
using namespace std;
class student{
    public:
    string name;
    string course;
    int roll;

    student(){//non parameterized contructor
        cout<<"the constructor is working::::\n";}

    student(string name,string course,int roll){//contructor oveloading:::
        name=name;
        course=course;
        roll=roll;}

    ~student(){//distructor
        cout<<"the distructor is working::::\n";}


    void setinfo(student &s1){
        cout<<"enter tha name\n"<<endl;
        cin>>s1.name;
        cout<<"enter tha course\n"<<endl;
        cin>>s1.course;
        cout<<"enter tha roll\n"<<endl;
        cin>>s1.roll;}
    
    void print(student &s1){
        cout<<s1.name<<endl;    
        cout<<s1.course<<endl;
        cout<<s1.roll<<endl;}

    void print(){
        cout<< "the student is not alloted yet:::\n"<<endl;}};



int main(){
student sumit;
sumit.setinfo(sumit);
sumit.print(sumit);
student kunal("kunal","cse",111);
student krit;
krit.print();



 
}