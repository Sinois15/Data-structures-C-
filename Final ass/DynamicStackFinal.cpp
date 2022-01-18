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

// display all elements in the stack
void displayStack(Node *cur) {
	if (isEmpty(cur))
		cout << "Nothing to display! Stack is empty.";
	else {
		while (cur) {//while cur is pointing to something
			cout << cur->data << " ";
			cur = cur->next;
		}	
	}
	cout<<endl;
}


//checking if a list is a palindrome
bool isPalindrome(Node **tmpList, int tmpRList[]){
	bool pal = true;
	int count = 0;
	if (isEmpty(*tmpList)){
		cout<<"Stack is empty!"<<endl;
	}
	else{
		while (!isEmpty(*tmpList)){
			if (pop(tmpList) != tmpRList[count]){
				pal = false;
			}
			count++;
		}

	return pal;
    }
}

int main() {
	//initialising the stack
	Node *list = NULL;
	//Node *tmpList = NULL;
	//Node *rList = NULL;
	int num, size = 0;
	

	cout<<"Please enter your list. Enter -1 to stop the input process. "<<endl;
	//inputting the list into a stack
	while (num != -1){
		cout<<"input a number: ";
		cin>>num;
		if (num != -1){
			push(&list, num);
			size++;
		}
	}
	int rList[size];
	Node *cur = list;//creating another pointer pointing to the bottom of the stack
	for(int i = size; i>0; i--) {//entering the list into an array in reverse order
			rList[i-1] = cur->data;
			cur = cur->next;	
	}
	cout<<"your list: ";
	displayStack(list);
	cout<<"your reversed list: ";
	for (int i = 0; i<size; i++){
		cout<<rList[i]<<" ";
	}
	cout<<endl;
	if (isPalindrome(&list, rList)){
		cout<<"Your list is a palindrome."<<endl;
	}
	else{
		cout<<"Your list is not a palindrome."<<endl;
	}

}