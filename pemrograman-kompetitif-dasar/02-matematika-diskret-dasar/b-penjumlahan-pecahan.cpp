#include <bits/stdc++.h>
using namespace std;

long long int sekutu(long long int m, long long int n) {
    if(m%n == 0) return n;
    else return sekutu(n, m%n);
}

int main(){
    long long int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    
    long long int pemb = (a*d) + (b*c);
    long long int peny = b*d;
    long long int x = sekutu(pemb, peny);
    
    if(x > 1) cout << pemb/x << " " << peny/x << endl;
    else cout << pemb << " " << peny << endl;
    return 0;
}