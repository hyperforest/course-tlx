#include <bits/stdc++.h>
using namespace std;

int main(){
    char m[1001],n[1001],a[1001],b[1001];
    cin >> m;
    cin >> n;
    if(strlen(n)>strlen(m)) swap(m,n);

        for(int i=0; i<=strlen(n); i++){
            if(m[i]!=n[i]){
                int k=0;
                for(int j=i; j<=strlen(n); j++){
                    a[k]=m[j+1]; b[k]=n[j]; k++;
                }
                break;
            }
        }
    
    if(strcmp(a,b)==0) cout << "Tentu saja bisa!" << endl;
    else cout << "Wah, tidak bisa :(" << endl;
    
}