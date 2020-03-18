#include <iostream>
using namespace std;

int N, A[75][75], B[75][75];

bool ident(int N) {
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if(A[i][j] != B[i][j]) return false;
      }
   }
   return true;
}

bool vert(int N) {
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if(A[i][j] != B[i][N-1-j]) return false;
      }
   }
   return true;
}

bool hor(int N) {
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if(A[i][j] != B[N-1-i][j]) return false;
      }
   }
   return true;
}

bool dign(int N) {
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if(A[i][j] != B[j][i]) return false;
      }
   }
   return true;
}

bool digi(int N) {
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if(A[i][j] != B[N-1-j][N-1-i]) return false;
      }
   }
   return true;
}

int main() {
   cin >> N >> N;
   
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> A[i][j];
      }
   }
   
   cin >> N >> N;
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> B[i][j];
      }
   }
   
   if(ident(N)) cout << "identik\n";
   else if(vert(N)) cout << "vertikal\n";
   else if(hor(N)) cout << "horisontal\n";
   else if(dign(N))  cout << "diagonal kanan bawah\n";
   else if(digi(N)) cout << "diagonal kiri bawah\n";
   else cout <<"tidak identik\n";
}