#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// class stack{
//     vector<int> v;

//     public:

//     void push(int val){
//         v.push_back(val);}

//     void pop(){
//         v.pop_back();}

//     int top(){
//         return v[v.size()-1];}


// };

bool isvalidparanthesis(string ch){
    int n = ch.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (ch[i] == '(' || ch[i] == '[' || ch[i] == '{'){
            st.push(ch[i]);
        }else{
            if(st.size() == 0){return false;}

            if ((st.top() == '(' && ch[i] == ')') ||
            (st.top() == '[' && ch[i] == ']')||
            (st.top() == '{' && ch[i] == '}')){st.pop();
            
            }else{return false;}}}

    return st.size() == 0;}





int main(){

    stack<int> s;
    s.push(2);
    s.push(3);
    

}