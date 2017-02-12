//Program swaps two nodes of linked list rather than
//swapping the field from the node.

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

//Function to swap two nodes.
void swapNode(node** head, int x, int y);

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
    //Call function to swap two nodes.
    swapNode(&head, 6, 2);
    //Display the modified list.
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

void swapNode(node** head, int x, int y){
    //Check if x is equal to y.
    if(x == y) return;

    //Create two pointers to store current value and prev value.
    node* current_x = *head;
    node* prev_x = NULL;
    //Search the node with data equal to x.
    while(current_x!=NULL && current_x->data!=x){
        prev_x = current_x;
        current_x = current_x->next;
    }

    node* current_y = *head;
    node* prev_y = NULL;
    //Search for y, keeping track of current and prev node.
    while(current_y!=NULL && current_y->data!=y){
        prev_y = current_y;
        current_y = current_y->next;
    }
    
    //case1: x and/or y are not present in list.
    if(current_x == NULL || current_y == NULL) return;

    //case2: if x is the head node.
    if(prev_x == NULL){
        *head = current_y;
    }
    //If x is not the head node.
    else{
        prev_x->next = current_y;
    }

    //case3: if y is the head node.
    if(prev_y == NULL){
        *head = current_x;
    }
    //If y is not the head node.
    else{
        prev_y->next = current_x;
    }
    //Swap next pointers.
    node* temp = current_x->next;
    current_x->next = current_y->next;
    current_y->next = temp;

}