#include <iostream>
#include <time.h>
using namespace std;

#define MAXL 20000

int aList[MAXL];
int bList[MAXL];
int size;

void displayList(int data[], int size) {
	for (int k = 0; k < size; k++)
		cout << data[k] << " ";
	cout << endl;
}

void bubbleSort(int data[], int size){
	int i, j; // for looping twice
	int temp; // to score the value being swapped

	for (i=0; i< size; i++) {
		for (j=0; j< size-i-1; j++) {
			if (data[j] > data[j+1]) { // swap occurs if this condition is met
				cout << "Swapping " <<  data[j+1] << " & " << data[j] << endl;
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
}

void selectionSort(int data[], int size){
	int temp; // for storing a value to be swapped
	int max_index; // index of max value
	int rightmost, current;
	
	for (rightmost=size-1; rightmost>0; rightmost--){
		//finding the largest item in the unsorted part of the array
		//rightmost is the end point of the unsorted part of array
		max_index = 0; //variable to store the largest element
		for (current=1; current<=rightmost; current++)
			if (data[current] > data[max_index])
				max_index = current;
		//swap the largest element with last element if necessary
		if (data[max_index] > data[rightmost]){
			cout << "Swapping " <<  data[rightmost] << " & " << data[max_index] << endl;
			temp = data[max_index]; // swap
			data[max_index] = data[rightmost];
			data[rightmost] = temp;
		}
	}
}


int main() {
    clock_t timeBefore, timeAfter;
    double timeTaken;

    srand(time(NULL));
    for (int k = 0; k < MAXL; k++){
        aList[k] = rand() % 100;
        bList[k] = aList[k];
    }
	
	
	cout << "BUBBLE SORT -> ";
	displayList(aList, 5);

    timeBefore = clock();
	bubbleSort(aList, MAXL);
    timeAfter = clock();
    timeTaken = (timeAfter - timeBefore);
    cout<<"BUBBLE SORT N = "<< MAXL <<" TIME = "<<timeTaken<<"ms\n";
	cout << "SELECTION SORT -> ";
	displayList(bList, 5);
    timeBefore = clock();
	selectionSort(bList, MAXL);
	timeAfter = clock();
	timeTaken = (timeAfter - timeBefore);
	cout<<"SELECTION SORT N = "<< MAXL <<" TIME = "<<timeTaken<<"ms\n";
	return 0;
}

//log3(n) + 5n + 2log2(n) + n2
void process(){

}