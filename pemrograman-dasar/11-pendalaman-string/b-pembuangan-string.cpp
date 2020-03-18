#include <bits/stdc++.h>
using namespace std;


int main(){
   string S, s;
   cin >> S >> s;
   
   int L = S.length(), l = s.length(), counter = 1;

   while(counter > 0) {
      counter = 0;
      for(int i = 0; i < S.length(); i++) {
         if(S.substr(i, l) == s) {
            S.erase(i, l);
            counter++;
            i--;
         }
      }
   }
   
   cout << S << endl;
}