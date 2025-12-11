#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

bool isalphanumeric(char s){
    if ((s>='0'&& s<='9')||(tolower(s)>='a' && tolower(s)<='z')){
        return true;}
        return false;}

bool palindrome(char s[],int n){
    int st=0;
    int end=n-1;

    while(st<end){
    if (!isalphanumeric(s[st])){
        st++;
        continue;}

    if (!isalphanumeric(s[end])){
        end--;
        continue;}
    
    
        if (tolower(s[st])  !=  tolower(s[end]))  {
            return false;}
        st++;end--;}}


int compress(string s){
    int n=s.length();
    int index=0;
    for (int i = 0; i<=n; i++){
        char ch= s[i];
        int count=0;


        while (i<n && ch==s[i]){
            count++;
            i++;}

        if (count==1)        {s[index++]=ch;}

        else{
            s[index++]=ch;
            string str=to_string(count);
            for(char dig:str){
                s[index++]=dig;}}
                i--;}
    s.resize(index);
    return index;}


string isprime(int n){
    string ans="";
    for (int i = 2; i*i <= n; i++){

        if (n%i==0)       {ans = "not prime";}
        else              {ans="prime";}}
        cout<<ans;}



int sieve(int n){
    vector<bool> isprime(n+1,true);
    int count=0;
    for (int  i = 2; i < n; i++){
        if (isprime[i]){
            count++;
            for (int j=i*2; i < n; j=j+i){
            isprime[j]=false;}}}
    return count;}


int euclid(int a,int b){
    while (a>0&&b>0){
        if (a>b)            {a=a%b;}
        else                {b=b%a;}}

    if (a==0)               {return b;}
    else                    {return a;}}










int main(){

    cout<<euclid(20,28);
}
