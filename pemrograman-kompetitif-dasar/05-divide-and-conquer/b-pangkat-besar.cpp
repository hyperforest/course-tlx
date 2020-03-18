#include<iostream>
#include<cmath>
#include<stack>
#define ll long long
using namespace std;

int sjt = 1000000;
bool lebih = false;

ll f(ll A, ll B) {
    if(B == 0) return 1;
    if(B == 1) return A;
    if(B%2 == 1) return (A*(f(A,B-1)%sjt))%sjt;
   
    ll c = f(A, B/2)%sjt;
    if(c >= sjt) lebih = true;
    return (c*c)%sjt;
}

int main() {
   ll A, B;
   cin >> A >> B;
   
   ll res = f(A, B);
   
   if(pow(A,B) < 1000000) cout << pow(A,B) << endl;
   else if(lebih) cout << res << endl;
   else {
        stack<int> S;
        int digit = 0;
        while(digit < 6) {
            S.push(res%10);
            res /= 10;
            digit++;
        }
        while(!S.empty()) {
            cout << S.top();
            S.pop();
        }
        cout << endl;
   }
   
}