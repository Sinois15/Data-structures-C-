#include <iostream>
using namespace std;
int main(){
    int x,num;
    cout<<"Enter a number: ";
    cin>>num;
    if (num>=0){
        for(x=0;x<=num;x++)
            cout<<x<<" ";
    }
    else 
        cout<<"Please provide a positive number!";
        return 0;
}