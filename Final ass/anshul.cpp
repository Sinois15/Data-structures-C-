#include <iostream>
using namespace std;

// basic structure of a dynamic stack node is given below
struct Node {
	int data;
	Node *next;
};

// code to check if the stack is empty, returns true if it is empty
bool isEmpty(Node *tmpTop) {
	return (tmpTop == NULL);
}

// code to display all the elements in a stack
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

// code to add a new element to the top of the stack
void push(Node **tmpTop, int n) {
	
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *tmpTop;
	*tmpTop = newNode;
}

// code to remove an element from the top of the stack
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

// returns the total amount of elements in the stack
int stackSize(Node *cur) {

	int count = 0;
	while (cur) {
		cur = cur->next;
		count++;
	}
	return count;
}

bool isPal(Node **tmpTop, int tmpArray[], int tmpSize){

    int checker = 0;
    for (int i = 0; i <= tmpSize; i++){
        if(tmpArray[i] == pop(tmpTop))
            checker++;
    }

    if(checker == tmpSize)
        return true;

    return false;
}
int main(){

    Node *top = NULL;
    Node *tmpTop = NULL;
    int entry;

     while(entry != -1){
        cout << "Entry: ";
        cin >> entry;
        if(entry != -1)
            push(&top, entry);
            push(&tmpTop, entry);
    }
    
    cout << "Top Stack: ";
    displayStack(top);
    /*cout << endl << "tmpTop Stack: ";
    displayStack(tmpTop);
    displayStack(tmpTop); */

    int size = stackSize(top);
    //cout << "Size: " << size << endl;

    int revArray[size];

    for(int i = (size); i > 0; i--){
        revArray[i] = tmpTop->data;
        tmpTop = tmpTop->next;
        cout<<revArray[i]<<" ";
    }

    /*for(int i = 0; i < size; i++){
            cout << revArray[i] << " ";
        }*/

    if (isPal(&top, revArray, size))
        cout << "The above list IS a Palindrome. " << endl;
    else 
        cout << "The above list IS NOT a Palindrome. " << endl;

    


    return 0;
}