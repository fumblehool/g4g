//Linked list implementation in C++
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

//Function to traverse the linked list
void traversal(node* head);

int main(){
    
    //Create three node 
    node* head = new node();
    node* node1 = new node();
    node* node2 = new node();

    head->data = 1;
    head->next = node1;

    node1->data = 2;
    node1->next = node2;

    node2->data = 3;
    node2->next = NULL;

    traversal(head);
    return 0;
}

void traversal(node* head){
    cout<<"List is : ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}