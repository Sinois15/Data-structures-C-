#include <iostream>
using namespace std;
int main(){
    int num, x=0;
    cout<<"Enter a number: ";
    cin>>num;
    if (num>=0){
        do{
            cout<<x<<" ";
            x++;
        }while(x<=num);
    }
    else{
        cout<<"Please enter a positive number!";
        cout<<"\n";
    }
    
    return 0;
}