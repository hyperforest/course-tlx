#include <bits/stdc++.h>
using namespace std;

void rec(int N) {
    if(N/2 != 0) rec(N/2);
    cout << N%2;
}

int main() {
    int N;
    cin >> N;
    
    rec(N);
    cout << endl;
}