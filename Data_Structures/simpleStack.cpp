#include <iostream>
using namespace std;

#define MAX 5//setting the size of the array as a constant
//structure of the stack
struct Stack{
    int data[MAX];
    int top;
};
//checking if the stack is full
bool isFull(int tmpTop){
    return(tmpTop + 1) == MAX;
}
//checking if the stack is empty
bool isEmpty(int tmpTop){
    return(tmpTop == -1);
}
//checking how many elements are in the stack
int getSize(Stack tmpStack){
    return tmpStack.top + 1;
}
//adding an element
void push(Stack *ptrStack, int n){
    if (isFull(ptrStack->top ))
        cout<<"Stack is full! push aborted!\n";

    else{
        ptrStack->top++;
        ptrStack->data[ptrStack->top] = n;
    }
}
//display the contents of the stack
void displayStack(Stack tmpStack){
    for(int x=0;x<=tmpStack.top;x++){
        cout<< tmpStack.data[x]<<" ";
    }
    cout<<"TOP\n";
}

//removing an element from the stack. 
//Deleting the element is not necessary as it would be replaced when a nre element is added 
int pop(Stack *ptrStack){
    int data = -1;
    if (isEmpty(ptrStack->top)){
        cout<< "Stack is empty! Pop aborted!\n";
    }
    else{
        data = ptrStack->data[ptrStack->top];
        ptrStack->top--;
    }
    return data;

}

int main(){
    Stack s;
    s.top = -1;
    cout<< "SIZE = "<< getSize(s)<<endl;
    push(&s,11);
    push(&s,22);
    push(&s,33);
    cout<< "SIZE = "<< getSize(s)<<endl;
    displayStack(s);//11 22 33
    cout<<"POP "<< pop(&s)<<endl;
    displayStack(s);//11 22

}