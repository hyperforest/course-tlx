#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
 cin >> N;
 
 while(N > 1) {
    if(N%2 != 0) {
        cout << "bukan" << endl;
        return 0;
    }
    N = N/2;
 }
 cout << "ya" << endl;
}