#include <iostream>
using namespace std;

// define structure of a dynamic queue
struct Node {
	int data;
	Node *next;
};

// check if queue is empty
bool isEmpty(Node *tmpFront) {
	return (tmpFront == NULL);
}

// display all elements in the queue
void displayQueue(Node *cur) {
	if (isEmpty(cur))
		cout << "Nothing to display! Queue is empty!";
	else {
		while (cur) {
			cout << cur->data << " ";
			cur = cur->next;
		}	
	}
	cout << endl;
} 

// add a new element to the end of a queue
void enqueue(Node **tmpFront, int n) {
	
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	
	if (isEmpty(*tmpFront))
		*tmpFront = newNode;
	else {
		Node *cur = *tmpFront;
		while (cur->next != NULL){
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

// remove an element from front of queue
int dequeue(Node **tmpFront) {

	int data = -1;
	if (isEmpty(*tmpFront))
		cout << "Unable to dequeue! Queue is Empty\n";
	else {
		Node *oldFront = *tmpFront;
		*tmpFront = oldFront->next;
		data = oldFront->data;
		delete oldFront;
	}
	return data;
} 


// return total elements counted in the queue
int queueSize(Node *tmpFront) {

	Node *cur = tmpFront;
	int count = 0;
	while (cur) {
		cur = cur->next;
		count++;
	}
	return count;
}

int main() {
	Node *front = NULL;

	displayQueue(front);
	enqueue(&front, 22);	
	enqueue(&front, 33);	
	enqueue(&front, 44);	
	displayQueue(front);
	cout << "SIZE = " << queueSize(front) << endl;
	cout << "DEQUEUE " << dequeue(&front) << endl;
	displayQueue(front);
	cout << "DEQUEUE " << dequeue(&front) << endl;
	displayQueue(front);
	cout << "DEQUEUE " << dequeue(&front) << endl;
	displayQueue(front);
	cout << "DEQUEUE " << dequeue(&front) << endl;
	displayQueue(front);
    return 0;
}