#include <bits/stdc++.h>
using namespace std;

int main() {
 int N, k;
 cin >> N >> k;
 for(int i = 1; i <= N; i++) {
    if(i%k != 0) cout << i;
    else cout << "*";
    if(i != N) cout << " ";
    else cout << endl;
 }
}