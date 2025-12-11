#include<iostream>
#include<vector>
using namespace std;

int smallest(int arr[5]){  //INT_MIN 
    int smallest = INT8_MAX ;
    int index=0;
    for (int i = 0; i <5; i++){
        if (arr[i]<smallest){
            smallest=arr[i];
            index=i;}}
    cout<<smallest<<endl;
    cout<<index;
    return index;}


int linearsearch(int arr[],int n,int t){
    for (int i = 0; i < n; i++){
        if (arr[i]==t){
            return i;}}}

int reverse(int arr[],int n){
    for (int i = 0; i < n; i++){
        arr[i]=arr[n-i-1];}}

int printarray(int arr[],int n){
    for (int i = 0; i <n; i++){
        cout<<arr[i]<<"\t";}}

int vectorsum(vector<int>){

}


int main(){
    int arr[]={2,4,5,6,8};
    reverse(arr,5);
    printarray(arr,5);

}