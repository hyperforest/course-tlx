#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A, B, C, N;
bool lebih = false;

ll pangkat(ll A, ll B) {
    if (B == 0) return 1;
    if (B == 1) return A;

    ll c = pangkat(A, B / 2);

    if (B % 2 == 0) return (c * c) % N;

    return (A * ((c * c) % N)) % N;
}

int main() {
    cin >> A >> B >> C >> N;
    
    ll hasil = A;

    for (int i = 1; i <= C; i++) {
        hasil = pangkat(hasil, B);
        hasil = hasil % N;
    }

    cout << hasil + 1 << endl;
}