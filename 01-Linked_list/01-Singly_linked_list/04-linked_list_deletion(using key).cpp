//Program to implement deletion in a linked list.

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
void deleteNode(node** head, int key);

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


void deleteNode(node** head, int key){
    //Temporary store the head value
    node* temp = *head;
    node* prev;
    //Check if head contains the key.
    if(temp!=NULL && temp->data == key){
        //Make head point to second node.
        *head = temp->next;
        //Free the memory with delete.
        delete temp;
        return;
    }

    //Traverse the list and search for the key.
    while(temp!=NULL &&temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    //if key is not present in linked list.
    if(temp==NULL) return;

    //Make the next of prev to point to next of link
    //to be deleted.
    //Unlink the node.
    prev->next = temp->next;

    //Free the memory.
    delete temp;
}
