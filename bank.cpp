#include<iostream>
#include<string.h>
using namespace std;
class bank{
    public:
    string branch;
    int ifsc;};

class employee{
    string name;
    string department;};

class costumer:public bank{
    private:
    int accno;

    public:
    string name ;

    void setter(string name ,int accno){
        this->name=name;
        this->accno=accno;}
    
    void print(){
        cout<<name<<endl;
        cout<<accno<<endl;
}


};
int main(){
    costumer sumit;
    sumit.setter("sumit",47868999);
    sumit.print();
}