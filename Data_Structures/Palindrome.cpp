#include <iostream>
using namespace std;

// define structure of a static stack
#define MAX 10

struct Stack {
	char letter[MAX];
	int top;
};

// check if stack is empty
bool isEmpty(int tmpTop) {
	return (tmpTop < 0);
}

// check if stack is full
bool isFull(int tmpTop) {
	return (tmpTop == (MAX-1));
}

// display all elements in the stack
void displayStack(Stack tmpStack) {
	if (isEmpty(tmpStack.top))
		cout << "Stack is empty!\n";
	else {
		for (int k = 0; k <= tmpStack.top; k++)
			cout << tmpStack.letter[k] << " ";
		cout << "TOP\n";
	}
}

// add a new element to the top of the stack
void push(Stack *ptrStack, char n) {
	if (isFull(ptrStack->top))
		cout << "Stack is full! Push aborted\n";
	else {
		ptrStack->top++;
		ptrStack->letter[ptrStack->top] = n;
	}
}

// remove an element from the top of the stack
char pop(Stack *ptrStack) {

	char letter = '>';
	if (isEmpty(ptrStack->top))
		cout << "Stack is empty! Pop aborted\n";
	else {
		letter = ptrStack->letter[ptrStack->top];
		ptrStack->top--;
	}
	return letter;
}

// return total elements counted in the stack
int displaySize(Stack tmpStack) {
	return (tmpStack.top + 1);
}

bool isPalindrome(Stack *ptrStack, char tmpWord[]){
	bool pal = true;
	int count = 0;
	while(tmpWord[count] != NULL){
		if(pop(ptrStack) != tmpWord[count]){
			pal = false;
		}
		count++;
	}
	return pal;
}

int main() {
	Stack aStack;
	aStack.top = -1;
	char word[MAX];
	cout << "Enter a word: ";
	cin >> word;
	int count = 0;
	while(word[count] != NULL){
		push(&aStack, word[count]);
		count++;
	}
	displayStack(aStack);
	if(isPalindrome(&aStack, word)){
		cout << word << " is a palindrome!" << endl;
	} else {
		cout << word << " is not a palindrome!" << endl;
	}
	return 0;
}