#include<bits/stdc++.h>
using namespace std;

int f(int A, int B, int K, int x) {
    if(K != 1) return abs(A*f(A, B, K-1, x)+B); 
    return abs(A*x+B);
}

int main() {
    int A, B, K, x;
    cin >> A >> B >> K >> x;
    
    cout << f(A, B, K, x) << endl;
}