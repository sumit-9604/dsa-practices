#include<iostream>
#include<string.h>
using namespace std;


class complex{
    public:
    int real;
    int imag;


int  display(){
    cout<<real<<endl;
    cout<<imag<<endl;}

    complex(int r,int i){
        this->real=r;
        this->imag=i;}

    complex operator +(complex obj){
        complex result(0,0);
        result.real=real+obj.real;
        result.imag=imag+obj.imag;
        return result;}};


int main(){
    complex c1(2,4);
    complex c2(64,5);
    complex c3=c1+c2;
    c3.display();



}