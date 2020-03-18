#include <bits/stdc++.h>
using namespace std;


int main(){
   string s1, s2, s3, s4, s5;
   cin >> s1 >> s2 >> s3 >> s4;
   
   //deleting
   for(int i = 0; i < s1.length(); i++) {
      if(s1.substr(i, s2.length()) == s2) {
         s1.erase(i, s2.length());
         break;
      }
   }
   
   //finding and replacing
   for(int i = 0; i < s1.length(); i++) {
      if(s1.substr(i, s3.length()) == s3) {
         int n = i+s3.length();
         
         //replacing
         s5 = s1.substr(n, s1.length()-1);
         s1.erase(n, s5.length());
         s1 += s4+s5;
         break;
      }
   }
   
   
   cout << s1 << endl;
}