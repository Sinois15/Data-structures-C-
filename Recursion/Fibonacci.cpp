#include <iostream>
using namespace std;

//F(n) = F(n-1) + F(n-2)
int iFibo(int n){
    if (n<=1) { 
        return n;
    }
    
    int a = 0;//(n-2)
    int b = 1;//(n-1)
    for (int k = 2; k<= n; k++){
        int c = b + a;
        a = b;
        b = c;
    }
        return b;
} 

int rFibo(int n){
    if (n<=1) { 
        return n;
    }
    else{
        return (rFibo(n-1) + rFibo(n-2));
    }

}


int main(){
    int num;
    cout<<"Enter a positive number: ";
    cin>>num;
    cout<<"iterative Fibonacci: "<<iFibo(num)<<endl;
    cout<<"recursion Fibonacci: "<<rFibo(num)<<endl;
    return 0;
}