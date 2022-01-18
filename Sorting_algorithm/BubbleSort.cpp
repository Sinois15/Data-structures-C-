#include <iostream>
using namespace std;
#define size 7






int main(){
    
    int num[size] = {  6, 32, 7, 2, 99, 31, 53  };
    int x, y, temp;
    for (x = 0; x<size; x++){
        cout<<"iteration "<<(x+1)<<": ";
        for (x = 0; x<size; x++){
            cout<<num[x]<<" ";
        }
        cout<<"\n";
        for (y=0; y<size-x-1; y++){
            if (num[y]>num[y+1]){
                cout<<"Swapping "<<num[y]<<" & "<<num[y+1]<<"\n";
                temp = num[y+1];
                num[y+1] = num[y];
                num[y] = temp;
            }
        }
        

    }
    cout<<"sorted list: ";
    for (x = 0; x<size; x++){
        cout<<num[x]<<" ";
    }

    return 0;
}