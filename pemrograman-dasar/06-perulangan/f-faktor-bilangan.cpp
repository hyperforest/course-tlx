#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
 cin >> N;

 for(int i = N; i >= 1; i--){
    if(N%i == 0) cout << i << endl;
 }
}