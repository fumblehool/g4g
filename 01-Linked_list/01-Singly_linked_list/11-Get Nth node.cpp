//Program which returns the value at Nth node 

#include<iostream>
using namespace std;

//Linked list node.
struct node{
    int data;
    node* next;
};

//Function to insert node at the front of Linked list.
void insertAtFront(node** head, int new_data);

//Function to traverse the list.
void traversal(node* head);

//Function to get the value of Nth node.
int GetNth(node* head, int n);

int main(){
    //Created an empty linked list.
    node* head = NULL;

    //Created 7 nodes.
    insertAtFront(&head, 7);
    insertAtFront(&head, 6);
    insertAtFront(&head, 5);
    insertAtFront(&head, 4);
    insertAtFront(&head, 3);
    insertAtFront(&head, 2);
    insertAtFront(&head, 1);
    //Display the list.
    traversal(head);
    //Print value of Nth node.    
    cout<<"Element at index 2 is :"<<GetNth(head, 2);
   
    return 0;
}


void insertAtFront(node** head, int new_data){
    //a. Create a new node.
    node* newNode = new node();

    //b. Put data in the node.
    newNode->data = new_data;

    //c. Make next of node as head.
    newNode->next = *head;

    //d. Make head point to new node.
    *head = newNode;
    //Time complexity of insertAtFront() is O(1) as it does constant work.
}


void traversal(node* head){
    cout<<"List is : ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int GetNth(node* head, int n){
    //Initialise count to 0.
    int count = 0;
    //Temporary pointer to head.
    node* ptr = head;
    //Goto the nth node.
    while(ptr!=NULL){
        //If we have reached nth node, return value.
        if(count == n){
            return ptr->data;
        }
        ptr = ptr->next;
        count++;
    }
    cout<<"Index out of Range"<<endl;
    return -1;
}