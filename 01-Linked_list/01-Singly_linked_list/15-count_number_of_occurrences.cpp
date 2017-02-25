//Program to find number of times given integer occurs in linked list. 

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

//Function to find occurrence of given integer.
int count(node* head, int n);


int main(){
    //Created an empty linked list.
    node* head = NULL;

    //Created 7 nodes.
    insertAtFront(&head, 7);
    insertAtFront(&head, 1);
    insertAtFront(&head, 5);
    insertAtFront(&head, 1);
    insertAtFront(&head, 1);
    insertAtFront(&head, 2);
    insertAtFront(&head, 1);
    //Display the list.
    traversal(head);
    //find number of times.
    cout<<"Count of 1 is : "<<count(head, 1)<<endl;
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

//Traverse the list and increase count if
//given integer is encountered.
int count(node* head, int n){
    //Temporary pointer to head.
    node* current = head;
    //Calculate number of times.
    int times = 0;
    while(current!=NULL){
        if(current->data == n){
            times++;
        }
        current = current->next;
    }

    return times;
    //Time complexity is O(n).
}
