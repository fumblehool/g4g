//Program which returns the value of middle node 

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
//Function to get the value of middle node.
int GetMiddleNode1(node* head);

//Method 2
//Function to get the value of middle node.
int GetMiddleNode2(node* head);

//Method 3
//Function to get the value of middle node.
int GetMiddleNode3(node* head);

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
    cout<<"Middle node Using Method1 is: "<<GetMiddleNode1(head)<<endl;
    cout<<"Middle node Using Method2 is: "<<GetMiddleNode2(head)<<endl;
    cout<<"Middle node Using Method3 is: "<<GetMiddleNode3(head)<<endl;
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
//Find the middle number and traver to that node.
int GetMiddleNode1(node* head){
    //Initialise count to 0.
    int count = 0;
    //Temporary pointer to head.
    node* ptr = head;
    //Calculate number of nodes.
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    //find the middle number.
    int index = 0, c = 0;
    index = count/2;
    ptr = head;
    while(ptr!=NULL){
        if(c == index){
            return ptr->data;
        }
        c++;
        ptr = ptr->next;
    }
}

//Method 2
//Take two pointers - slow and fast.
//For every fast->next->next, slow->next
//slow will point to middle node.
int GetMiddleNode2(node* head){
    //Two nodes slow and fast.
    node *slow = head, *fast = head;
    if( head!=NULL){

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return slow->data;
}

//Method 3
int GetMiddleNode3(node* head){
    node *ptr = head, *mid = head;
    int count = 0;
    if( head!=NULL){
        while(ptr!=NULL){
            if(count%2!=0){
                mid = mid->next;
            }
            count++;
            ptr = ptr->next;
        }
    }
    return mid->data;
}

