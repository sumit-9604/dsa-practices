#include<iostream>
#include<string.h>
using namespace std;
class person{
    public:
    string name;
    int mno;};

class employee :virtual public person{   //to prevent diamond problem 
    int eid;                             // ambguety and redundancy
    public:
    string dept;
    int salary;

    employee(string n,int e,string d,int s){  ///constructor for setting values
        name=n;
        eid=e;
        dept=d;
        salary=s;}

friend void print(employee a);};
    
void print(employee a){
    cout<<"name is::"<<a.name<<endl;
    cout<<"eid is::"<<a.eid<<endl;
    cout<<"depatrment is::"<<a.dept<<endl;
    cout<<"salary is ::"<<a.salary<<endl;};



class department :public employee, virtual public person{
    public:
    int depid;
    int shift;
    string field;};


int main(){
employee sumit("sumit",4567,"management",100000);
print(sumit);
    


    

}
