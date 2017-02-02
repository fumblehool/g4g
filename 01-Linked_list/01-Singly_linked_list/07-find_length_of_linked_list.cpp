//Find the length of Linked list or number of nodes(Recursion & Iteration).

#include<iostream>
using namespace std;

//Linked list node.
struct node{
    int data;
    node* next;
};

//Function to insert node at the front of Linked list.
void insertAtFront(node** head, int new_data);

//Function to return number of nodes using iteration.
int count_using_iteration(node* head);

//Function to return number of nodes using recursion.
int count_using_recursion(node* head);

int main(){
    //Created an empty linked list.
    node* head = NULL;

    //Created 5 nodes.
    insertAtFront(&head, 1);
    insertAtFront(&head, 3);
    insertAtFront(&head, 1);
    insertAtFront(&head, 2);
    insertAtFront(&head, 1);
    
    //Using iteration.
    cout<<"Number of nodes are : "<<count_using_iteration(head)<<endl;

    //Using recursion.
    cout<<"Number of nodes are : "<<count_using_recursion(head)<<endl;
    
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

int count_using_iteration(node* head){
    //Created temporary pointer.
    node* ptr = head;
    //Create variable result to store the number of nodes.
    int result = 0;

    while(ptr != NULL){
        //make ptr to point to next node i.e. ptr->next.
        ptr = ptr->next;
        //Add 1 to to number of nodes.
        result++;
    }
    //Return the total number of nodes.
    return result;
}

int count_using_recursion(node* head){
    //Base condition
    //Check if head is NULL.
    if(head == NULL){
        return 0;
    }
    
    //Recusively call the function.
    else{
        return 1 + count_using_recursion(head->next);
    }
}