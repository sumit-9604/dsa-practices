#include <iostream>
#include<string.h>
using namespace std;

class teacher{
    public:
    string name;
    int tid;
    string dept;
    int salary;

};


int main() {
    teacher t1;
    t1.name = "sumit";
    t1.tid=15610;
    t1.dept="computer science";
    t1.salary=100000;
    cout<<"the name of teacher is " << t1.name <<" and tid is "<< t1.tid<<endl;


}
