#include <iostream>
using namespace std;
int main(){
    int num,x=0;
    cout<<"Enter a number: ";
    cin>>num;
    if (num>=0){
        while (x<=num){
            cout<<x<<" ";
            x++;
        }
    }
    else
    {
        cout<<"Please enter a positive number!";
        cout<<"\n";
    }
    return 0;
    
}