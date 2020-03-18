#include <bits/stdc++.h>
using namespace std;


int main(){
   string S;
   int k;
   
   cin >> S >> k;
   for(int i = 0; i < S.length(); i++) {
      if(S[i]+k <= 122) printf("%c", S[i]+k);
      else printf("%c", S[i]+k-26);
   }
   cout << endl;
}