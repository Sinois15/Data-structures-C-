#include <iostream>
#include <time.h>
using namespace std;

#define max 100

int lList[max];
int bList[max];
int bStep = 0;//number of steps for binary search
int lStep = 0;//number of steps for linear search
int searchVal=0;
int searchPos=0;

void displayList(int list[]){
    for (int k =0; k < max; k++){
        cout<<list[k]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int data[], int size){
	int i, j; // for looping twice
	int temp;

	for (i=0; i< size; i++) {
		for (j=0; j< size-i-1; j++) {
			if (data[j] > data[j+1]) { // need to swap
				//cout << "Swapping " <<  data[j+1] << " & " << data[j] << endl;
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
		//displayList(data, size);
	}
}

//complexity is O(n)
int linearSearch(int list[], int searchVal){
    int pos = -1;//if -1 is returned then search has failed
    for (int k = 0; k < max; k++){
        lStep++;
        if (list[k] == searchVal){
            pos = k;
            break;
        }
    }
    return pos;
}

//complexity of binary search is O(logn)
int binarySearch(int list[], int first, int last, int searchVal){
    int pos = -1;
    int mid;
    if (first > last){//invalid list
        pos = -1;
    }
    else{
        mid = (last + first)/2;
        bStep++;
        if (searchVal == list[mid]){
            pos = mid;
        }
        else if (searchVal > list[mid]){
            pos = binarySearch(list, mid+1, last, searchVal);
        }
        else{
        pos = binarySearch(list, first, mid-1, searchVal);
        }
    }
    return pos;
}

int main(){
    srand(time(NULL));
    for (int k = 0; k< max; k++){
        lList[k] = rand() % 1000;
        bList[k] = lList[k];
    }
    
    displayList(lList);
    cout<<"Enter search value: ";
    cin>>searchVal;
    searchPos = linearSearch(lList, searchVal);
    if (searchPos == -1){
        cout<<"Search unsuccessful. Value not found."<<endl;
        cout<<"STEPS TAKEN = "<<lStep<<endl;
    }
    else{
        cout<<"LINEAR SEARCH FOR "<<searchVal<<" FOUND AT POS "<<searchPos<<endl;
        cout<<"STEPS TAKEN = "<<lStep<<endl;
    }
    bubbleSort(bList, max);
    displayList(bList);
    cout<<"Enter search value: ";
    cin>>searchVal;
    searchPos = binarySearch(bList, 0, max, searchVal);
    if (searchPos == -1){
        cout<<"Search unsuccessful. Value not found."<<endl;
        cout<<"STEPS TAKEN = "<<bStep<<endl;
    }
    else{
        cout<<"BINARY SEARCH FOR "<<searchVal<<" FOUND AT POS "<<searchPos<<endl;
        cout<<"STEPS TAKEN = "<<bStep<<endl;
    }
    return 0;
}
//if bubbleSort is used(complexity: O(n^2) then the sorting is the dominant term)