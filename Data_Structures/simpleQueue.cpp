//code is incomplete
#include <iostream>
using namespace std;
#define max 5

struct Queue{
    int data[max];
    int front=0;
    int rear=-1;
};

bool isFull(Queue tmpQueue){
    return (getSize(tmpQueue)) == max;
}

bool isEmpty(Queue tmpQueue){
    return (getSize(tmpQueue)) == 0;
}

void enqueue(Queue *ptrQueue, Queue tmpQueue, int n){
    if (isFull(tmpQueue)){
        cout<< "Queue is full! Enqueue aborted!\n";
    }
    else if ((ptrQueue -> rear) == max){
        ptrQueue -> rear = 0;
        ptrQueue -> data[ptrQueue -> rear] = n;
    }
    else{
        ptrQueue -> rear++;
        ptrQueue -> data[ptrQueue -> rear] = n;
    }
}

int dequeue(Queue *ptrQueue, Queue tmpQueue){
    int data = -1;
    if (isEmpty(tmpQueue)){
        cout<< "Queue is empty! Abort dequeue!\n";
    }
    else if ((ptrQueue -> front) == max){
       data = ptrQueue -> data[ptrQueue -> front]; 
       ptrQueue -> front = 0;
    }
    else {
        data = ptrQueue -> data[ptrQueue -> front];
        ptrQueue -> front++; 
    }
}

void display(Queue *ptrQueue, Queue tmpQueue){
    if (isEmpty(tmpQueue)){
        cout<<"Queue is empty!\n";
    }
    else {
        while(!isEmpty(tmpQueue)){
            cout<< tmpQueue.front<<" ";
            dequeue(ptrQueue, tmpQueue);
        }
    }
}

int getSize(Queue tmpQueue){
    return tmpQueue.rear + 1;
}


int main(){

}