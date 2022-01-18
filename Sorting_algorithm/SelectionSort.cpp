#include <iostream>
using namespace std;
#define size 7

int main(){
    int num[size] = {  6, 32, 7, 2, 99, 31, 53  };
    int cur, rightmost, temp, maxIndex, x, n=0;
    for (rightmost = size -1; rightmost>0; rightmost--){
        maxIndex = 0;
        cout<<"iteration "<<(n+1)<<": ";
        for (x = 0; x<size; x++){
            cout<<num[x]<<" ";
        }
        n++;
        cout<<"\n";
        for (cur = 1; cur<=rightmost; cur++){
            if (num[cur] > num[rightmost]){
                maxIndex = cur;
            }
            if (num[maxIndex] > num[rightmost] ){
                cout<<"Swapping "<<num[maxIndex]<<" & "<<num[rightmost]<<"\n";
                temp = num[maxIndex];
                num[maxIndex] = num[rightmost];
                num[rightmost] = temp;

            }
        }
        
    }
    cout<<"sorted list: ";
    for (x = 0; x<size; x++){
        cout<<num[x]<<" ";
    }

    return 0;
}