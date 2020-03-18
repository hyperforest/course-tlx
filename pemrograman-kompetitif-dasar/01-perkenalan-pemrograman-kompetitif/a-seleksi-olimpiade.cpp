#include <bits/stdc++.h>
#define l1(i) list[i].score1
#define l2(i) list[i].score2
#define l3(i) list[i].score3
#define ls(i) list[i].name
using namespace std;

struct id{
   string name;
   int score1, score2, score3;
};

int main() {
   int T;
   cin >> T;
   
   for(int i = 1; i <= T; i++) {
      int N, M;
      cin >> N >> M;
      
      id list[N];
      
      string query;
      cin >> query;
      
      for(int i = 0; i < N; i++) {
         cin >> list[i].name
            >> list[i].score1
            >> list[i].score2
            >> list[i].score3;
      }
      
      for(int i = 0; i < N; i++) {
         for(int j = i+1; j < N; j++) {
            if(l3(i) < l3(j)) {
               int temp = l1(i);
               l1(i) = l1(j);
               l1(j) = temp;
               temp = l2(i);
               l2(i) = l2(j);
               l2(j) = temp;
               temp = l3(i);
               l3(i) = l3(j);
               l3(j) = temp;
               string temb = ls(i);
               ls(i) = ls(j);
               ls(j) = temb;
            }
            else if(l3(i) == l3(j)) {
               if(l2(i) < l2(j)) {
                  int temp = l1(i);
                  l1(i) = l1(j);
                  l1(j) = temp;
                  temp = l2(i);
                  l2(i) = l2(j);
                  l2(j) = temp;
                  temp = l3(i);
                  l3(i) = l3(j);
                  l3(j) = temp;
                  string temb = ls(i);
                  ls(i) = ls(j);
                  ls(j) = temb;
               }
               else if(l2(i) == l2(j)) {
                  if(l1(i) < l1(j)) {
                     int temp = l1(i);
                     l1(i) = l1(j);
                     l1(j) = temp;
                     temp = l2(i);
                     l2(i) = l2(j);
                     l2(j) = temp;
                     temp = l3(i);
                     l3(i) = l3(j);
                     l3(j) = temp;
                     string temb = ls(i);
                     ls(i) = ls(j);
                     ls(j) = temb;
                  }
               }
            }
         }
      }
      
      bool ketemu = false;
      for(int i = 0; i < M; i++) {
         if(ls(i) == query) {
            cout << "YA" << endl;
            ketemu = true;
            break;
         }
      }
      if(ketemu == false) cout << "TIDAK" << endl;
   }
}