#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int X) {
   return abs(a*X + b);
}

int main() {
   int A, B, x, K;
   cin >> A >> B >> K >> x;
   
   int n = f(A, B, x);
   for(int i = 2; i <= K; i++) {
      n = f(A, B, n);
   }
   
   cout << n << endl;
}