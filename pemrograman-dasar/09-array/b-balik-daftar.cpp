#include <bits/stdc++.h>
using namespace std;


int main() {
 int N, k=-1, m;
 int a[1000];

 while(cin >> N) {
    k++;
    a[k] = N;  
 }
 for(int i = k; i >= 0; i--){
    cout << a[i] << endl;
 } 
}