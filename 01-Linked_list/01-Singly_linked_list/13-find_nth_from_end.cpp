//Program which returns the value of Nth node from end. 

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

//Method 1
//Function to get the value of Nth node from end.
int GetNthFromRear1(node* head, int n);

//Method 2
//Function to get the value of Nth node from end.
int GetNthFromRear2(node* head, int n);


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
    //Print value of middle node.
    cout<<"-1 shows wrong input"<<endl;    
    cout<<"4th node from last Using Method1 is: "<<GetNthFromRear1(head, 4)<<endl;
    cout<<"5th node from last Using Method2 is: "<<GetNthFromRear2(head, 5)<<endl;
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

//Method 1
//Traverse the list and find the number of nodes.
//Find the l-n+1 node from beginning.
int GetNthFromRear1(node* head, int n){
    //Initialise count to 0.
    int count = 0;
    //Temporary pointer to head.
    node* ptr = head;
    //Calculate number of nodes.
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }

    if(count<n){
        return -1;
    }

    ptr = head;
    for(int i=1;i<count-n+1;i++){
        ptr = ptr->next;
    }
    return ptr->data;
}

//Method 2
//Take two pointers - main and reference.
//Make reference equal to nth node from start.
//for every reference->next, make main->next.
int GetNthFromRear2(node* head, int n){
    //Two nodes main and ref.
    node *main = head, *ref = head;
    //Take count to find Nth node from start.
    int count = 0;

    if( head!=NULL){
        while(count<n){
            //If n>length_of_linked_list
            if(ref==NULL){
                return -1;
            }
            //Goto next node.
            ref = ref->next;
            //Increment counter.
            count++;
        }
    }
    //Find (len-N)th node from start.
    while(ref!=NULL){
        ref = ref->next;
        main = main->next;
    }
    return main->data;
}
