#include <bits/stdc++.h>
using namespace std;

int main() {
 int N, k = 0;
 cin >> N;

 for(int i = 1; i <= N; i++){
    for(int j = 1; j <= i; j++) {
        cout << k;
        k++;
        if(k > 9) k = 0;
    }
    cout << endl;
 }
}