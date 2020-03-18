#include <bits/stdc++.h>
using namespace std;

int T, M, R, C, A[129][129];
vector<string> vec;

void extract(int i, int j, int pointer, string path, int N);

int main() {
   cin >> T;
   for(int i = 0; i < T; i++) {
      string q;
      cin >> q;
      vec.push_back(q);
   }
   
   cin >> R >> C;
   M = max(R, C);
   M = 1 << (int)ceil((double)(log10(M))/(double)(log10(2)));
   
   for(int i = 0; i < T; i++) {
      extract(1, 1, 1, vec[i], M);
   }

   for(int i = 1; i <= R; i++) {
      for(int j = 1; j <= C; j++) {
         cout << A[i][j];
         if(j != C) cout << " ";
      }
      cout << endl;
   }
}

void extract(int i, int j, int pointer, string path, int N) {
   if(path.length() == 1) {
      for(int p = i; p <= i+N-1; p++) {
         for(int q = j; q <= j+N-1; q++) {
            A[p][q] = 1;
         }
      }
   }

   else if(path.length() == pointer) {
      for(int p = i; p <= i+N-1; p++) {
         for(int q = j; q <= j+N-1; q++) {
            A[p][q] = 1;
         }
      }
   }
   
   else {
      if(path[pointer] == '0') extract(i, j, pointer+1, path, N/2);
      else if(path[pointer] == '1') extract(i, j+N/2, pointer+1, path, N/2);
      else if(path[pointer] == '2') extract(i+N/2, j, pointer+1, path, N/2);
      else if(path[pointer] == '3') extract(i+N/2, j+N/2, pointer+1, path, N/2);
   }
}