#include <iostream>
using namespace std;

struct Node{
        int data;
        Node *next;
};
//method for creating the first node 
void initNode(Node *tmpHead, int n){
    tmpHead-> data=n;
    tmpHead-> next=NULL;
}
//method for adding nodes at the end
void addNode(Node *cur, int n){
    Node *newNode = new Node;
    newNode-> data = n;
    newNode-> next=NULL;
    while(cur-> next!= NULL){
        cur = cur->next;
    }
    cur->next=newNode;
}    
//method for displaying the list
void displayNode(Node *cur){
    while (cur!=NULL){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}
//method for adding a node at the front
void addFront(Node **tmpHead, int n){//**temphead will point to the address of head
    //initialising newNode
    Node *newNode = new Node;
    newNode->data = n;
    //making newNode point to what head is pointing(the current first node)
    newNode->next=*tmpHead;
    //making head point to newNode
    *tmpHead = newNode;
    
}
//method for removing the first node
void removeFront(Node **tmpHead){
    if ((*tmpHead)-> next== NULL)
        cout<<"single linked list!! Removal aborted!!\n";
    else{
    Node *oldNode = *tmpHead;
    *tmpHead = oldNode -> next;
    delete oldNode;
    }
}
//method for removing a node a the end
void removeNode(Node *cur){
    if (cur-> next== NULL)
        cout<<"single linked list!! Removal aborted!!\n";
    else{
        while(cur->next->next!= NULL)
            cur=cur->next;
            delete cur->next;
            cur->next=NULL;
        }

    
}
//method for counting the number of nodes
int getTotalNode(Node *cur){
    int count = 0;
    while(cur!=NULL){
        count++;
        cur=cur->next;
    }
    return count;
}
int main(){
    Node *head = new Node;
    initNode(head, 22);
    addNode(head, 33);
    displayNode(head);
    addFront(&head,11);
    displayNode(head);
    cout<<getTotalNode(head)<<endl;
    removeFront(&head);
    displayNode(head);
    removeNode(head);
    displayNode(head);
    cout<<getTotalNode(head)<<endl;
    return 0;
}