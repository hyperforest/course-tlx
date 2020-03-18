#include <bits/stdc++.h>
#define f(i, a, b, j) for(int i = a; i < b; i+=j)
using namespace std;

int main() {
   int R, C;
   cin >> R >> C;
   char a[R][C];
   
   f(i, 0, R, 1) {
      f(j, 0, C, 1) {
         cin >> a[i][j];
      }
   }
   
   bool masih = false; //apakah setelah diruntuhin, masih ada yang 1 semua ato ga
   while(masih == false) {
      int L; //Last, baris terakhir yang 1 semua
      
      //ngecek mana aja baris yang isinya 1 semua
      f(i, 0, R, 1) {
         char val = 1;
         f(j, 0, C, 1) {
            val *= a[i][j]-48;   //ascii
         }
         //kalo 1 semua, direset jadi 0 semua
         if(val == 1) {
            f(j, 0, C, 1) {
               a[i][j] = '0';
            }
            L = i;
            masih = true;
         }
      }
      
      //nampilin hasil sementara setelah diruntuhin
//      cout << endl;
//      f(i, 0, R, 1) {
//         f(j, 0, C, 1) {
//            cout << a[i][j];
//         }
//         cout << endl;
//      }
      
      //diruntuhin
      int N = L;
      if(masih == true) {
         for(int k = 0; k < C; k++){
            L = N;
            while(a[L][k] == '0' and L < R) {
               L++;
            }
            
            for(int i = 0; i < L; i++){
               for(int j = 0;j < L; j++){
                  if(a[i][k] < a[j][k]) {
                     int temp = a[i][k];
                     a[i][k] = a[j][k];
                     a[j][k] = temp;
                  }
               }
            }
         }
      }
      
      if(masih == true) masih = false; //biar dicari ulang masih ada yg 1 semua ato ga barisnya
      else masih = true; //biar ga infiniteloop
   }
   
   //nampilin
   f(i, 0, R, 1) {
      f(j, 0, C, 1) {
         cout << a[i][j];
      }
      cout << endl;
   }
}