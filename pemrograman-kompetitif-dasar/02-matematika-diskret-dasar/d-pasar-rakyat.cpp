#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
   if(a%b == 0) return b;
   return gcd(b, a%b);
}

int main() {
   int N;
   cin >> N;
   int a[N];
   
   cin >> a[0];
   for(int i = 1; i < N; i++) {
      cin >> a[i];
      a[i] = a[i]*a[i-1]/gcd(a[i],a[i-1]);
   }
   cout << a[N-1] << endl;
}