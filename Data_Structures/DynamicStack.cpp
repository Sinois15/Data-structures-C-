#include <iostream>
using namespace std;



// define structure of a dynamic stack
struct Node {
	int data;
	Node *next;
};

// check if stack is empty
bool isEmpty(Node *tmpTop) {
	return (tmpTop == NULL);
}

// display all elements in the stack
void displayStack(Node *cur) {
	if (isEmpty(cur))
		cout << "Nothing to display! Stack is empty.";
	else {
		while (cur) {
			cout << cur->data << " ";
			cur = cur->next;
		}	
	}
	cout << endl;
} 

// add a new element to top of stack
void push(Node **tmpTop, int n) {
	
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *tmpTop;
	*tmpTop = newNode;
}

// remove an element from top of stack
int pop(Node **tmpTop) {

	int data = -1;
	if (isEmpty(*tmpTop))
		cout << "Unable to pop! Stack is empty.\n";
	else {
		Node *oldTop = *tmpTop;
		*tmpTop = oldTop->next;
		data = oldTop->data;
		delete oldTop;
	}
	return data;
} 


// return total elements counted in the stack
int stackSize(Node *cur) {

	int count = 0;
	while (cur) {
		cur = cur->next;
		count++;
	}
	return count;
}

int main() {
	
	Node *top = NULL;

	displayStack(top);
	push(&top, 22);	
	push(&top, 33);	
	push(&top, 44);	
	displayStack(top);
	cout << "SIZE = " << stackSize(top) << endl;
	cout << "POP " << pop(&top) << endl;
	displayStack(top);
	cout << "POP " << pop(&top) << endl;	
	displayStack(top);
	cout << "POP " << pop(&top) << endl;	
	displayStack(top);
	cout << "POP " << pop(&top) << endl;	
	displayStack(top);
    return 0;
}