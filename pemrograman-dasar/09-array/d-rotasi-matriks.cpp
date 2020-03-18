#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    int a[R][C];

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }

    for(int j = 0; j < C; j++) {
        for(int i = R-1; i >= 0; i--){
            cout << a[i][j];
            if(i != 0) cout << " ";
        }
        cout << endl;
    }   
}