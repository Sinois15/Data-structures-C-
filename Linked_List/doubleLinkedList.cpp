#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void initNode(Node *tmpHead,int n){
    tmpHead->data = n;
    tmpHead->next = NULL;
    tmpHead->prev = NULL;
}

void addNode(Node *cur,int n){
    while(cur->next != NULL){
        cur = cur->next;
    }
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    cur->next = newNode;
    newNode->prev = cur;
}

void displayNode(Node *cur){
    while(cur!=NULL){
        cout<< cur->data <<"->";
        cur = cur->next;
    }
    cout<<endl;
    
}

void displayReverse(Node *cur){
    while(cur->next!= NULL)
        cur = cur->next;
    
    while(cur!=NULL){
        cout<< cur->data<<"->";
        cur = cur->prev;
    }
    cout<<endl;
        
}

void addFront(Node **tmpHead, int n){
    Node *newNode = new Node;
    newNode->data = n;
    newNode->prev = NULL;
    newNode->next = *tmpHead;
    (*tmpHead)->prev = newNode;
    *tmpHead = newNode;
    
}

void removeFront(Node **tmpHead){
    if ((*tmpHead)->next == NULL){
        cout<<"Single node linked list! Abort removeFront\n ";
    }
    else{
        (*tmpHead) = (*tmpHead)-> next;
        delete (*tmpHead) -> prev;
        (*tmpHead) -> prev = NULL;
    }
}


int main(){
    Node *head = new Node;
    initNode(head,22);
    addNode(head,33);
    addNode(head,44);
    addNode(head,55);
    addFront(&head,11);
    displayNode(head);
    cout<<endl;
    displayReverse(head);
    removeFront(&head);
    displayNode(head);
    cout<<endl;
    displayReverse(head);
    return 0;
}