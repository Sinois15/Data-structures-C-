#include <iostream>
using namespace std;
//creating the template for the nodes
int main(){
struct Node {
    int data;
    Node *next;
};
//note: when a pointer is created,it points to an anonymous node which is created at the same time 
//creating pointer head(along with anonymous node x)
Node *head = new Node;
//initializing x
head->data = 10;
head->next =NULL;
//creating pointer newNode along with anonymous node y
Node *newNode = new Node;
//initializing y
newNode->data = 20;
newNode->next = NULL;
//creating pointer cur and initializing it with head(hence it points to what head is pointing to i.e x)
Node *cur = head;
while(cur) {// can also be written as while(cur!=NULL){
    if(cur->next == NULL) {//if what cur is pointing to i.e x.next == NULL
        cur->next = newNode;//x.next now points to y
    break;//jumps out of loop
}
cur = cur->next;//whatever cur->next(i.e x.next) is pointing to, cur now also points to it. 
//So cur now points to y
//in simple terms: it through forward through the list
}
cur = head;//cur points back to x
while(cur) {
    cout << cur->data << " ";//output data of node to which cur is pointing to
    cur = cur->next;//whatever cur->next(i.e x.next) is pointing to, cur now also points to it. 
//So cur now points to y
}
//note: line 30-35 is to go through the list from the start
//output: 10 20 
return 0;
}