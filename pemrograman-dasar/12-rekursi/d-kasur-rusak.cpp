#include <bits/stdc++.h>
using namespace std;

bool check(string a, int i, int j) {
    if(i-j == 0 or i - j == 1) return true;
    if(a[i] == a[j]) return check(a, i+1, j-1);
    return false;
}

int main() {
    string S;
    cin >> S;
    
    if(check(S, 0, S.length()-1) == true) cout <<  "YA\n";
    else cout << "BUKAN\n"; 
}