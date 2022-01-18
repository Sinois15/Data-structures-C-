#include <iostream>
using namespace std;
#define size 7

int num[7] = {  6, 32, 7, 2, 99, 31, 53  };

void insertionSort(int arr[], int n){
    int i, j, k, cur;//cur is going to be the one which will be moved back within the array
    for (i = 1; i < n; i++){//starting array at second index to compare to the previous item in array
        
        cout<<"\n";
        cur = num[i];//cur takes value at current index in for loop
        j = i-1;// j takes the value of the previous index
        while(j >= 0 && num[j] > cur){//condition is met if cur is greater than the value stored in the prevoius index
                                      //and if j is 0 or positive, that is still points to an array index 
            num[j+1] = num[j];//moves the a value one spot forward if its greater than cur 
            j--;//decrements j to repeat the process with preceeding values 
        }//loops until there is nothing greater than cur before it

        num[j+1] = cur;//places cur before all greter values
                       //if nothing is greater before cur, this line changes nothing
                       //if j=-1(which is why loop terminated), places cur in first array index

        cout<<"iteration "<<i<<": ";//stating current iteration number
        for (k = 0; k < n; k++){//display current state of array
            cout<<num[k]<<" ";
        }
    }
    cout<<endl;
}

void displayUnsorted(){
    cout<<"unsorted list: ";
    for (int i = 0; i < size; i++){
        cout<<num[i]<<" ";
    }
}

void displaySorted(){
    cout<<"sorted list: ";
    for (int i = 0; i < size; i++){
        cout<<num[i]<<" ";
    }
}

int main(){
    displayUnsorted();
    insertionSort(num, size);
    displaySorted();
}