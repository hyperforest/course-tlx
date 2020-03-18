#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int N) {
   for(int i = 0; i < N; i++) {
      cout << arr[i];
      if(i != N-1) cout << " ";
   }
   cout << endl;
}

void swap(int m[], int n[], int i, int j) {
   int temp = m[i];
   m[i] = n[j];
   n[j] = temp;
}

int main() {
   int N;
   cin >> N;
   int a[N], b[N];
   for(int i = 0; i < N; i++) cin >> a[i];
   for(int i = 0; i < N; i++) cin >> b[i];
   
   int Q, x, y;
   char p, q;
   cin >> Q;
   for(int i = 1; i <= Q; i++) {
      cin >> p >> x >> q >> y;
      if(p == 'A') {
         if(q == 'A') swap(a, a, x-1, y-1);
         else swap(a, b, x-1, y-1);
      }
      else {
         if(q == 'A') swap(b, a, x-1, y-1);
         else swap(b, b, x-1, y-1);
      }
   }
   
   printArr(a, N);
   printArr(b, N);
}