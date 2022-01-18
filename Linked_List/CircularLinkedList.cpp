#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void initNode(Node *tmpHead, int n){
    tmpHead-> data=n;
    tmpHead-> next=tmpHead;//since its circular, there is no null and the first node points to itself
    
}

void addNode(Node *tmpHead, int n){
    Node *cur = tmpHead;
    Node *newNode = new Node;
    newNode-> data=n;
    newNode-> next=tmpHead;
    while(cur->next!=tmpHead){
        cur= cur->next;
    }
    cur->next=newNode;
}

void displayNode(Node *tmpHead){
    Node *cur = tmpHead;
    do{
        cout<< cur->data<<" ";
        cur = cur->next; 
    }while(cur!=tmpHead);
    cout<<endl;
}

void addFront(Node **tmpHead, int n){
    Node *cur = *tmpHead;
    Node *newNode = new Node;
    newNode-> data = n;
    newNode-> next = *tmpHead;
    
    do{
        cur = cur->next;
    }while(cur->next!=*tmpHead);
    *tmpHead = newNode;
    cur->next = newNode;
    
}

void removeFront(Node **tmpHead){
    if ((*tmpHead)->next == *tmpHead){
        cout<<"Single node linked list. Abort reoveFront!\n";
    }
    else{
        Node *cur = *tmpHead;
        (*tmpHead) = (*tmpHead)->next;

    }
}

int main(){
    Node *head = new Node;
    initNode(head, 22);
    addNode(head, 33);
    addNode(head, 44);
    displayNode(head);
    addFront(&head, 11);
    displayNode(head);
    return 0;
}