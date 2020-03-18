#include <bits/stdc++.h>
using namespace std;

void pegunungan(int N) {
   if(N >= 2) pegunungan(N-1);
   for(int i = 1; i <= N; i++) cout << "*";
   cout << endl;
   if(N >= 2) pegunungan(N-1);
}

int main() {
   int N;
   cin >> N;
   
   pegunungan(N);
}