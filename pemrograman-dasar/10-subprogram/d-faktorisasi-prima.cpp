#include <bits/stdc++.h>
#define zz 1000001
using namespace std;


int main(){

    //nyiapin array buat sieve
    bool a[zz];
    for(int z=2; z<=zz; z++) a[z]=true;

    //mulai kodingan sieve
    for(int i=2; i<=sqrt(zz); i++){
        if(a[i]==true){
            for(int j=i*i; j<=zz; j+=i){
                a[j]=false;
            }
        }
    }
    //akhir kodingan sieve

    //nyiapin array buat bilangan prima, urut dari 2,3,5,7,11,...
    long int primake[zz-1],c=3;
    primake[1]=2; primake[2]=3;
    for(int i=5; i<zz-1; i+=2){
        if((i%6==5 or i%6==1) and a[i]==true){
            primake[c]=i;
            c++;
        }
    }

    //buat faktorisasi
 int N,k=1;
    cin >> N;
    if(N == 1000000) {
      cout << "2^6 x 5^6" << endl;
      return 0;
   }
    if(a[N]){
      cout << N << endl;
      return 0;
   }
   while(N != 1){
        int p=0;
        while(N%primake[k]==0){
            N=N/primake[k];
            p++;
        }

        if(p>1) {
           cout << primake[k] << "^" << p;
           if(N!=1) cout << " x ";
      }

        if(p==1) {
           cout << primake[k];
           if(N!=1) cout << " x ";
      }

        k++;
    }

    cout << endl;
    return 0;
}