#include <bits/stdc++.h>
using namespace std;

int catat[10], cetak[10], N, ans = 0, K;
bool pernah[100];

void print(int counter, int start, int N, int D) {
   if(counter <= D) {
      for(int i = start; i <= N; i++) {
         cetak[counter] = i;
         print(counter+1, i+1, N, D); //for selanjutnya
      }
   }
   else {
      for(int i = 1; i < counter; i++) {
         cout << cetak[i];
         if(i != counter-1) cout << " ";
      }
      cout << endl;
   }
}

int main() {
   for(int i = 1; i < 10; i++) {
      catat[i] = i;
   }
   
   cin >> N >> K;
   print(1, 1, N, K);
}