//Program to implement deletion in a linked list using position.

#include<iostream>
using namespace std;

//Defining linked list node.
struct node{
    int data;
    node* next;
};


//Function to insert node at the front of Linked list.
void insertAtFront(node** head, int new_data);

//Function to traverse the list.
void traversal(node* head);

//Function which deletes the first occurance of key.
void deleteNode(node** head, int position);

int main(){

    /* Start with the empty list */
    node* head = NULL;
 
    insertAtFront(&head, 7);
    insertAtFront(&head, 1);
    insertAtFront(&head, 3);
    insertAtFront(&head, 2);
 
    //Show the linked list 
    traversal(head);
    deleteNode(&head, 1);

    //Linked list after deletion.
    cout<<"Linked List after Deletion at position 1: "<<endl;
    traversal(head);
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


void deleteNode(node** head, int position){
    //Temporary store the head value
    node* temp = *head;
    node* next;

    //Check if linked list is empty.
    if(temp==NULL) return;

    //Check if head needs to be removed.
    if(position == 0){
        //Make head point to second node.
        *head = temp->next;
        //Free the memory with delete.
        delete temp;
        return;
    }

    //Find previous node of the node to be deleted.
    for(int i=0;i<position-1 && temp!=NULL;i++){
        temp = temp->next;
    }

    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL) return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    next = temp->next->next;
 
    // Unlink the node from linked list
    delete temp->next;  // Free memory
 
    temp->next = next;  // Unlink the deleted node from list
}
