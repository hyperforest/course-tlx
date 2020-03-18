#include <bits/stdc++.h>
using namespace std;


int main(){
   string S;
   cin >> S;
   
   //checking
   for(int i = 0; i < S.length(); i++) {
      if(S[i] <= 90) printf("%c", tolower(S[i]));
      if(S[i] >= 97) printf("%c", toupper(S[i]));
   }
   cout << endl;
}