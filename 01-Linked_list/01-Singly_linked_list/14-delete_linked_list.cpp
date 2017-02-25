//Program which Deletes the linked list. 

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

//Function to Delete the linked list.
void deleteList(node** head);


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
    //Delete the linked list.
    deleteList(&head);
    cout<<"Linked list deleted"<<endl;
    cout<<"Head is: "<<head<<endl;
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

//Take two pointers.
//One point to current node and other to next node.
//delete the current node.
//current = next & next = next->next while next!=NULL
void deleteList(node** head){
    //Temporary pointer to head.
    node* current = *head;
    node* next;
    //Calculate number of nodes.
    while(current!=NULL){
        next = current->next;
        delete current;
        current = next;
    }

    *head = NULL;
}
