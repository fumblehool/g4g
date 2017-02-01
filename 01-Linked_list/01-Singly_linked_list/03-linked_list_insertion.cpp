/*Insert a new node in the linked list.
Node can be inserted in three ways-
1. At the front of linked list.
2. After a given node.
3. At the end of linked list. */

#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

//1. Function to insert node at the front of Linked list.
void insertAtFront(node** head, int new_data);

//2. Function to insert node after a given node.
void insertAfter(node* prev_node, int new_data);

//3. Function to insert node at the end of list.
void insertAtEnd(node** head, int new_data);

//Function to traverse the list.
void traversal(node* head);

int main(){
    
    node* head = NULL;
    // Insert 6.  So linked list becomes 6->NULL
    insertAtFront(&head, 6);
 
    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    insertAtFront(&head, 7);

    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    insertAtFront(&head, 1);

    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    insertAtEnd(&head, 4);

    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    //View the linked list
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


void insertAfter(node* prev_node, int new_data){
    //a. Check if the given prev_node is NULL
    if(prev_node == NULL){
        cout<<"Given prev_node is NULL"<<endl;
        return;
    }

    //b. Create a new node.
    node* newNode = new node();

    //c. Put data in the node.
    newNode->data = new_data;

    //d. Make the next of new node to the nex of prev_node.
    newNode->next = prev_node->next;

    //e. Make the nex to prev_node to point to new node.
    prev_node->next = newNode;
    //Time complexity of insertAfter() is O(1) as it does constant work.
}


void insertAtEnd(node** head, int new_data){
    //a. Create a new node.
    node* newNode = new node();

    //b. Put data in the node.
    newNode->data = new_data;

    //c. Make its next as NULL because it is the last node.
    newNode->next = NULL;

    //d. If list is empty, make this node as head.
    if(*head == NULL){
        *head = newNode;
    }

    //e. Traverse till the last node.
    node *ptr = *head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    //f. Change the next of last node to the new Node.
    ptr->next = newNode;
    return;
    
    //Time complexity of insertAtEnd() is O(n) because there are n nodes.
    //It can be optimised to work in O(1) by keeping extra pointer to tail.
}
