#include <bits/stdc++.h>
using namespace std;

int c[1000][1000]; //matriks hasil kali
int main() {
    int N, M, P;
    cin >> N >> M >> P;
    int a[N][M], b[M][P]; //matriks yg akan dikali
    //matriks pertama N baris x M kolom
    //matriks kedua M baris x P kolom

    //input
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    //input
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < P; j++) {
            cin >> b[i][j];
        }
    }

    //mengalikan
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P; j++) {
            for(int k = 0; k < M; k++) {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    //print
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P; j++) {
            cout << c[i][j];
            if(j != P-1) cout << " ";
        }
        cout << endl;
    }
}