#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node* child;

    node(int val){

        data = val;
        next = NULL;
        prev = NULL;
        child = NULL;
    }};

    node* flatten(node* head){
        node* curr = head;
        while(curr != NULL){
            
            if (curr -> child != NULL){
                node* next = curr -> next;
                curr -> next = flatten(curr -> child);
                curr -> next -> prev = curr; // flatered child branch connection to the orignal brnach
                curr -> child = NULL;

                while (curr->next !=NULL){
                    curr = curr -> next;}

                if(next != NULL){
                    curr -> next = next;
                    next -> prev = curr;}}

                curr = curr -> next;}

            return head;
    }
node* reversenodek(int k , node* head){

    node* temp = head;
    int count = 0;
    while (count < k){
        if (temp == NULL)   {return head;}
        temp = temp -> next;}
    
    node* prevnode = reversenodek(k , temp -> next ); 

    temp = head; count = 0;
    while(count < k){
        node* next = temp -> next;
        temp -> next = prevnode;
        prevnode = temp;
        temp = next;
        count++;}

    return prevnode;
}

node* swapnodes(node* head ){

    if(head == NULL || head -> next == NULL){return head;}

    node* first = head;
    node* prev = NULL;
    node* second = head -> next;

    while(first != NULL && second != NULL){
    node* third = second -> next;
    second -> next = first;
    first -> next = third;

    if(prev != NULL){   prev -> next = second;}
    else{   head = second;}
    
    prev = first;
    first = third;
    if(third != NULL){  second = third -> next;}
    else{second = NULL;}}

    return head;

}