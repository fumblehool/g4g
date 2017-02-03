//Program to implement searching in Linked list.
//Search an element in linked list (Iterative & Recursive)

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
bool search_using_iteration(node* head, int x);

//Function to return number of nodes using recursion.
bool search_using_recursion(node* head, int x);

int main(){
    //Created an empty linked list.
    node* head = NULL;

    //Created 5 nodes.
    insertAtFront(&head, 17);
    insertAtFront(&head, 3);
    insertAtFront(&head, 1);
    insertAtFront(&head, 12);
    insertAtFront(&head, 31);
    //Using iteration
    search_using_iteration(head, 12)?
    cout<<"Element Found!! using iteration"<<endl:cout<<"Not Found";
    //Using Recursion
    search_using_recursion(head, 12)?
    cout<<"Element Found!! using recursion"<<endl:cout<<"Not Found";
     
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

bool search_using_iteration(node* head, int x){
    //Created temporary pointer.
    node* ptr = head;
    //Traverse the list and check if element is present at the node.
    while(ptr != NULL){
        //Check if element is present.
        if(ptr->data == x) return true;
        //make ptr to point to next node i.e. ptr->next.
        ptr = ptr->next;
    }
    //Element is not present in the linked list.
    return false;
}

bool search_using_recursion(node* head, int x){
    //Base condition
    //Check if head is NULL.
    if(head == NULL) return false;
    //Check if element is present
    else if(head->data == x) return true;
    //Recusively call the function.
    else{
        search_using_recursion(head->next, x);
    }
}