#include <bits/stdc++.h>
using namespace std;


int main(){
    bool a[990000];
    for(int z=2; z<=990000; z++)
        a[z]=true;
        
    for(int i=2; i<=sqrt(990000); i++){
        if(a[i]==true){
            for(int j=i*i; j<=990000; j+=i){
                a[j]=false;
            }
        }
    }
    
    long int primake[77778],k=3;
    primake[1]=2; primake[2]=3;
    for(int i=5; i<=990000; i+=2){
        if((i%6==5 or i%6==1) and a[i]==true){
            primake[k]=i;
            k++;
        }
    }
    
    int cases,l;
    cin >> cases;
    for(int i=1; i<=cases; i++){
        cin >> l;
        cout << primake[l] << endl;
    }
}