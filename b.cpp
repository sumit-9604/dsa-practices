#include<iostream>
using namespace std;

int changebinary(int n){
    int ans=0;
    int pow=1;
    while(n>0){
        int r=n%2;
        n=n/2;
        ans=ans+(r*pow);
        pow=pow*10;}
        cout<<ans<<endl;}

int btod(int b){
    int ans=0;
    int pow=1;
    while (b>0){
        int r=b%10;
        b=b/10;
        ans=ans+(r*pow);
        pow=pow*2;}
        cout<<ans;
    }

int main(){
    changebinary(23);
    btod(110101010);
}