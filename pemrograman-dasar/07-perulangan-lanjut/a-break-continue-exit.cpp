#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
 cin >> N;

 for(int i = 1; i <= N; i++){
    if(i%10 != 0) cout << i << endl;
    if(i == 41 and N >= 42) {
     cout << "ERROR" << endl;
     break;
    }   
 }
}