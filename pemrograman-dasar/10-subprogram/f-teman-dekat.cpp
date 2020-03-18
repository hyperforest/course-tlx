#include <bits/stdc++.h>
using namespace std;

int closeness(int x[], int y[], int i, int j, int D) {
   return pow(abs(x[i]-x[j]), D) + pow(abs(y[i]-y[j]), D);
}

int main() {
   int N,  d;
   cin >> N >> d;
   int x[N], y[N], c[500000];
   
   for(int i = 0; i < N; i++) {
      cin >> x[i] >> y[i];
   }
   
   int k = 0;
   for(int i = 0; i < N; i++) {
      for(int j = i+1; j < N; j++) {
         c[k++] = closeness(x, y, i, j, d);
      }
   }
   
   sort(c, c+k);
   cout << c[0] << " " << c[k-1] << endl;
}