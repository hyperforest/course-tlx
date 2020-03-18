#include <bits/stdc++.h>
using namespace std;


int main() {
 int N, k, m;
 cin >> N;

 for(int i = 1; i <= N; i++){
    k = 0;
    cin >> m;
    for(int j = 2; j <= sqrt(m); j++) {
        if(m%j == 0) k++;
        if(k > 1) {
            cout << "BUKAN" << endl;
            break;
        }
    }
    if(k == 1 or k == 0) cout << "YA" << endl;
 }
}