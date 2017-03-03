//Program to detect loop in linked list. 

#include<iostream>
using namespace std;

//Linked list node.
struct node{
    int data;
    node* next;
    bool visited;
};

//Function to insert node at the front of Linked list.
void insertAtFront(node** head, int new_data);

//Function to traverse the list.
void traversal(node* head);

//Method1
/*Traverse the list and save the node address to Hash table.
If null is encountered, return false
If node address already exists in hash table, return true*/
//Time complexity is O(n) and Auxiliary Space: O(n) 


//Method2
/*Create a field visited in each node.
Traverse the node and mark visited as true.
If we encounter a node whose value of "visited" is true,
true else if Null is encountered return false*/
//Time complexity: O(n) and Auxiliary Space: O(n) 
bool detectloopMethod2(node* head);

//Method3
//Floyd’s Cycle-Finding Algorithm:
//Use two pointers, slow and fast.
//Both pointers point to head.
//For every slow->next, move fast->next->next;
//If NUll is encountered, return false.
//If slow == fast, return true.
bool detectloopMethod3(node* head);
//Time Complexity: O(n) && Auxiliary Space: O(1)
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
    detectloopMethod2(head);
    detectloopMethod3(head);
    cout<<"After making a loop in list."<<endl;
    //Make the loop in list.
    head->next->next->next->next = head;
    detectloopMethod2(head);
    detectloopMethod3(head);
    return 0;
}


void insertAtFront(node** head, int new_data){
    //a. Create a new node.
    node* newNode = new node();

    //b. Put data in the node.
    newNode->data = new_data;

    //c. Make next of node as head.
    newNode->next = *head;

    //d. Mark visited as false
    //This will help in method2
    newNode->visited = false;
    //e. Make head point to new node.
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

bool detectloopMethod2(node* head){
    
    node* ptr = head;
    while(ptr!=NULL){
        if(ptr->visited == true){
            cout<<"Loop Found: "<<endl;
            return true;
        }
        ptr->visited = true;
        ptr = ptr->next;
    }
    cout<<"Loop not found"<<endl;
    return false;
}

bool detectloopMethod3(node* head){
    node* slow = head;
    node* fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout<<"Loop Found"<<endl;
            return true;
        }
    }
    cout<<"No loop found"<<endl;
    return false;
}
