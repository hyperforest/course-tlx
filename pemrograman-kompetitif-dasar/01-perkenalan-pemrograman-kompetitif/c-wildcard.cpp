#include <bits/stdc++.h>
using namespace std;

int main() {
   string patokan = "", kiri = "", kanan = "";
   cin >> patokan;
   int N, L = patokan.length();

   //splitting sama * nya, disimpen sama si kiri kanan
   if(patokan[0] == '*') {
      if(patokan != "*") kanan = patokan.substr(1, L-1);
   }
   else if(patokan[L-1] == '*') {
      if(patokan != "*") kiri = patokan.substr(0,L-1);
   }
   else if(patokan != "*") {
      int u;
      for(int i = 0; i < patokan.length(); i++) {
         if(patokan[i] == '*'){
            u = i;
            break;
         }
         kiri += patokan[i];
      }
      for(int i = u+1; i < patokan.length(); i++) {
         kanan += patokan[i];
      }
   }

   //input query
   int Ki = kiri.length(), Ka = kanan.length();
   cin >> N;
   for(int i = 1; i <= N; i++) {
      string query;
      cin >> query;
      int M = query.length();

      //dicocokin satu2 sama kiri kanan
      if(patokan == "*") cout << query << endl;
      else if(kiri == "" and kanan != "") {
         if(M >= Ka) if(query.substr(M-Ka, Ka) == kanan) cout << query << endl;
      }
      else if(kiri != "" and kanan == "") {
         if(query.substr(0, Ki) == kiri) cout << query << endl;
      }
      else if(kiri != "" and kanan != "" and M >= Ka+Ki) {
         if(query.substr(0, Ki) == kiri and query.substr(M-Ka, Ka) == kanan) cout << query << endl;
      }
   }
}