#include <bits/stdc++.h>
using namespace std;

int A[129][129];
double R, C;
int Ch[129][129];
vector <string> ans; //buat jawaban

void bagi(int i, int j, string path, int N);

int main() {
   cin >> R >> C;
   
   //read
   for(int i = 1; i <= R; i++) {
      for(int j = 1; j <= C; j++) {
         cin >> A[i][j];
      }
   }
   
   //buat menyesuaikan
   R = max(R, C);
   R = 1 << (int)ceil(log10(R)/log10(2));
   
   
   bagi(1, 1, "", R);
   if(ans.size() == 0) cout << 0 << endl;
   else {
      cout << ans.size() << endl;
      for(int i = 0; i < ans.size(); i++) {
         cout << ans[i] << endl;
      }
   }
}

void bagi(int i, int j, string path, int N) {
   //i sebagai indeks baris, j sebagai indeks kolom, N sebagai ukuran submatriks persegi
   if(N != 1) {
      bool same = true;
      for(int k = i; k <= i+N-1; k++) {
         for(int l = j; l <= j+N-1; l++) {
            if(A[k][l] != 1) {
               same = false;
               break;
            }
         }
      }
      
      if(same == true) {
         ans.push_back("1"+path);
      }
      else {
         bagi(i, j, path+"0", N/2);
         bagi(i, j+N/2, path+"1", N/2);
         bagi(i+N/2, j, path+"2", N/2);
         bagi(i+N/2, j+N/2, path+"3", N/2);
      }
   }
   else {
      if(A[i][j] == 1) ans.push_back("1"+path);
   }
}