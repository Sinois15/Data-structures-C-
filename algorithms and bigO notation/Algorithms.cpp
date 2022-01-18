#include <iostream>
using namespace std;

void process(int n) {//linear because of constant m, O(c) or O(4)
 int m = 5;
 for (int k = 1; k < m; k++)
    n = n + k;
}

void process(int n) {//n-5, O(n)
 int m = 5;
 for (int k = m; k < n; k++)
    m = n + k;
}
//note: if there is no bracket and there are statement(s) between the the loops, they are not nested
void process(int n) {//(n-1)+(n-1) = 2n-2, O(n)
 for (int j = 1; j < n; j++)
    n = n * 1;
    for (int k = 1; k < n; k++)
      n = n * 1;
}
//nested becuz there is no statement in between the loops
void process(int n) {//9n, O(n)
 int m = 0;
    for (int p = 1; p < n; p++)
        for (int k = 1; k < 10; k++)
            m = n + k;
}

void process(int n) {//log2^n, O(logn)
 int tot = 0;
 for (int a = 1; a < n; a++) {
    n = n/2;
    tot = tot + n;
 }
}
//nested loop
void process(int n) {//9log3^n, O(logn)
 int tot = 0;
 for (int a = 1; a < 10; a++)
    for (int b = 1; b < n; b++) {
        n = n/3;
        tot = tot + n;
    }
}
//nested loops becuz brackets
void process(int n) {//nlog4^n, O(nlogn)
 int tot = 0;
 int m = n;
 for (int a = 1; a < m; a++) {
    tot = tot + a;
    for (int b = 1; b < n; b++) {
        n = n/4;
        tot = tot + n;
    }
 }
}

void process(int n) {//n-10, O(n)
 int tot = 0;
 if (n > 10) {
    int k = 1;
    while (k < n) {
        tot = tot + k;
        k++;
    }
 }
 else
 tot = 1;
}

//log3(n) + 5n + nlog2(n) + n2
void process(int n){
    int m = n;
    int tot = 0;
    // code segment for 5n
    for (int a = 1; a < 6; a++){
        for (int b = 0; b < n; b++){
        tot = a + n;
        }
    }
    //code segment for n^2
    for (int c = 0; c < n; c++){
        for (int d = 0; d < n; d++){
            tot = tot + d;
        }
    }
    //code segment for log3(n)
    for (int e = 0; e < n; e++){
        n = n/3;
        tot = tot + n;
    }
    //code segment for nlog2(n)
    for (int f = 0; f < m; f++){
        for (int g = 0; g < n; g++){
            n = n/2;
            tot = tot + m;
        }
    }
}
