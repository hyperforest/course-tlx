#include <bits/stdc++.h>
using namespace std;


int main(){
   string S, sc;
   cin >> S;
   
   bool ada = false;
   //checking and processing if S is a snake_case_styled string
   for(int i = 0; i < S.length(); i++) {
      if(S[i] == '_') {
         ada = true;
         S.erase(i,1);
         S[i] = toupper(S[i]);
      }
   }
   //processing if S is a camelCaseStyled string
   if(ada == false) {
      for(int i = 0; i < S.length(); i++) {
         if(S[i] <= 90) {
            sc = S.substr(i, S.length()-1); //replacing
            sc[0] = tolower(sc[0]);
            S.erase(i, S.length()-1);
            S += '_';
            S += sc;
         }
      }
   }
   
   cout << S << endl;
}