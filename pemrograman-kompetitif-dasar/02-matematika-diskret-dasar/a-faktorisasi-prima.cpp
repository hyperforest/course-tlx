#include <bits/stdc++.h>
using namespace std;


int main(){
    bool a[999984];
    for(int z=2; z<=999984; z++)
        a[z]=true;
        
    for(int i=2; i<=sqrt(999984); i++){
        if(a[i]==true){
            for(int j=i*i; j<=999984; j+=i){
                a[j]=false;
            }
        }
    }
    
    long int primake[784500],c=3;
    primake[1]=2; primake[2]=3;
    for(int i=5; i<=784500; i+=2){
        if((i%6==5 or i%6==1) and a[i]==true){
            primake[c]=i;
            c++;
        }
    }
    
    int N,k=1;
    cin >> N;
    int x=N;
    if(N==1) cout << "1";
    for(int i=1; i<=x; i++){
        int p=0;
        while(N%primake[k]==0){
            N=N/primake[k];
            p++;
        }
        
        if(p>1){
            cout << primake[k] << "^" << p;
            if(N!=1) cout << " x ";
        }
        if(p==1){
            cout << primake[k];
            if(N!=1) cout << " x ";
        }
        k++;
    }
    
    cout << endl;

}