#include<iostream>
#include<unordered_map>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next =NULL;
        prev = NULL;
    }
};

class doublyll{
    node* head;
    node* tail;
};