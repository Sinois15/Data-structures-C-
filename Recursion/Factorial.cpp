#include <iostream>
using namespace std;

//n! = n*(n-1)!
int iFact(int n){//using iterative solution
    int fac = 1;
    for (int k = 1; k<=n; k++){
        fac = k * fac;
    }
    return fac;
}

int rFact(int n){
    if (n<=1){
        return 1;
    }
    else
    return n*rFact(n - 1);
}

int main(){
    int num;
    cout << "Enter a positive integer: ";
    cin>> num;
    cout<< "Iterative Factorial ="<< iFact(num)<< endl;
    cout<< "Recursive Factorial ="<< rFact(num)<< endl;
    return 0;
}