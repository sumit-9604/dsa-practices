#include<iostream>
#include<unordered_map>
using namespace std;

// PHLE POINT KRENGE PHIR UODATE KRENGE NHO TO NEW NODE HAMESHA NULL HOGA


class node{             // for creating nodes
    public:
    int data;
    node* next;
    node* random;

    node(int val){
        data = val;
        next = NULL;
        random = NULL;
    }
};

class linkedlist{      // for linking all nodes
    node* head;
    node* tail;

public:
    linkedlist(){
        head = tail = NULL;} 



    void push_front(int val){
        node* newnode = new node(val);     // dynamically for using in main 

        if (head == NULL){
            head = tail = newnode;
            return;}
        else{
            newnode -> next = head;          // abhi head 1 hi hai but new node jo 2 hai uska next next ko head point krega jo abhi 1 hi hai uske baad head ko update kreange new node pr jo ki 2 hai
            head = newnode;
        }
    }

    void push_back(int val){
        node* newnode = new node(val);
        if (head == NULL){
            head = tail = newnode;}

        else{
            tail -> next = newnode;
            tail = newnode;
        }
        
    }

    void pop_front(){

        if(head == NULL){
            cout<<"linkedlist is empty"<<endl;}


        else{ 
        node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        // node seperatid
        delete temp;}

    }

    void pop_back(){
        if (head == NULL){
            cout<< " the linkedlist is empty"<<endl;}

        else{
            node* temp = head;
            while (temp -> next != tail){
               temp = temp -> next;}
               temp -> next =NULL;
               delete tail;
               tail = temp;
            

        }
    }


    void insert(int val , int position){
        
        if (position < 0){
            cout<<"invalid"<<endl;
            return;}

        if (position == 0){
            push_front(val);
            return;}
        

        
        node* temp = head;
        for (int i = 0; i < position-1; i++){
            if (temp == NULL)  {return;}
            
            temp = temp -> next;}

        node* newnode = new node(val);
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }


    int search(int num){
        int idx = 0;
        node* temp = head;
        while (temp != NULL){
            if (temp -> data == num){
            
            return idx;}
            temp = temp -> next;
            idx++;}}

    int  reverse(){
        node* prev = NULL;
        node* current = head;
        node* next = NULL;

        while (current != NULL)
        {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        return prev->data;
    }

    int middle(){
        node* slow = head;
        node* fast = head;
        while (fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next ->next;
        }
        return slow->data;

    }

    node* cycle(node* head){
        node* slow = head;
        node* fast = head;
        bool iscycle = false;

        while (fast != NULL && fast -> next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){       //detection of the cycly
                iscycle = true;
                break;}}

        if(!iscycle){return NULL;}
        slow = head;

        node* prev = NULL;
        while(slow != fast){           // start of the cycle
            slow = slow -> next;
            prev = fast;
            fast = fast -> next;
        }
        prev -> next = NULL;
        return slow;
    }
 

    node* merge(node* h1 , node* h2){

        if (h1 == NULL )  {return h2;}  // basecase
        if(h2 ==NULL)     {return h1;}

        if (h1 -> data <= h2 -> data){
            h1 -> next = merge(h1->next , h2);
            return h1;}
            
        else {
            h2->next = merge(h1,h2->next);
            return h2;}
    }


    node* copyrandom(node* head){
        
        

        if(head == NULL){return NULL;}

        unordered_map<node*, node*> track;
        node* newhead = new node(head -> data);
        node* oldtemp = head -> next;
        node* newtemp = newhead; 
        
        track[head] = newhead;
        while(oldtemp != NULL){
        node* copy = new node(oldtemp -> data);
        track[oldtemp] = copy;
        
        newtemp -> next = copy;
        oldtemp = oldtemp -> next;
        newtemp = newtemp -> next;}


        // for copy of the linkedlist
        
        oldtemp = head;
        newtemp = newhead;
        while(oldtemp != NULL){
            newtemp -> random = track[oldtemp -> random];
            oldtemp = oldtemp -> next;
            newtemp = newtemp -> next;}


        return newhead;
    
    
    
    
    
    }



    void print(){

        node* temp = head;
        while (temp != NULL){
            cout << temp -> data << endl;
            temp = temp -> next;}

        cout<<endl;}

};

int main() {

}


