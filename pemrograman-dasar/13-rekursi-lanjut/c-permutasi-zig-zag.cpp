#include <bits/stdc++.h>
using namespace std;

int catat[100], N, ans = 0;
bool pernah[100];

void print(int k, int n) {
   if(k > n) {
      
      bool ye = true;   //true kalo permutasi nya memenuhi aturan

      //buat ngecek dia memenuhi aturannya ato ga :
      if(n%2 == 0) {
         //kalo dia inputnya genap, berarti kan harus 1<6>2<5>3<4 atau 6>1<5>2<4>3
         //untuk kasus 1<6>2<5>3<4 dan indexing dari 1 :
         if(catat[1] < catat[2]) {
            for(int i = 3; i < n; i+=2) {
               if(catat[i-1] < catat[i] or catat[i] > catat[i+1]) {
                  ye = false; break;
               }
            }
         }
         //untuk kasus 6>1<5>2<4>3, indexing dari 1 :
         else {
            for(int i = 3; i < n; i+=2) {
               if(catat[i-1] > catat[i] or catat[i] < catat[i+1]) {
                  ye = false; break;
               }
            }
         }
      }
      
      else{
         //kalo inputnya ganjil sama aja idenya, cuma beda dikit di ngecek pemenuhan aturannya aja
         if(catat[1] < catat[2]) {
            for(int i = 2; i < n; i+=2) {
               if(catat[i-1] > catat[i] or catat[i] < catat[i+1]) {
                  ye = false; break;
               }
            }
         }
         else{
            for(int i = 2; i < n; i+=2) {
               if(catat[i-1] < catat[i] or catat[i] > catat[i+1]) {
                  ye = false; break;
               }
            }
         }
      }

      //kalo dia memenuhi aturan zigzag, baru di cout
      if(ye == true) {
         ans++;
         for(int i = 1; i <= n; i++) {
            cout << catat[i];
         }
         cout << endl;
      }
   }
   
   
   else {
      //kalo yang ini mulai buat rekursifnya
      for(int i = 1; i <= n; i++) {
         if(pernah[i] == false) {
            pernah[i] = true;
            catat[k] = i;
            print(k+1, n); //for selanjutnya
            pernah[i] = false;
         }
      }
   }
}

int main(){
   cin >> N;
   print(1, N);
//   cout << ans << endl;
}