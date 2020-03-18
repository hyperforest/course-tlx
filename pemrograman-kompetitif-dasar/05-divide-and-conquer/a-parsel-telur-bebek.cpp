#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Misal hitung(x) untuk menghitung banyak parsel
    yang dihasilkan given x butir telur
    Contoh:
    hitung(20) yang di sample test case =
    20 / 4 + 20 / 6 + 20 / 8 = 5 + 3 + 2 = 10
    jadi hitung(20) = 10

    Ide:
    Kita mau nyari range L dan R dimana
    hitung(L) = hitung(L + 1) = ... = hitung(R) = M

    Pasti berlaku
    hitung(1) <= hitung(2) <= ... <= hitung(2^63 - 1)

    Berarti kita bisa cari aja batas kiri sama batas
    kanan pake binary search, nanti jawabannya
    kanan - kiri + 1
*/

ll N, M, kiri, kanan;
ll A[300000];
ll maks = (1LL << 63) - 2;

ll hitung(ll x) {
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = (ans + x / A[i]);
    }
    return ans;
}

bool check0() {
    ll L = 1, R = maks;

    while (L <= R) {
        // cout << L << " " << R << endl;
        ll mid = (L + R) / 2;
        ll val = hitung(mid);

        if (val < M) L = mid + 1;
        else if (val > M) R = mid - 1;
        else return true;
    }

    return false;
}

ll cari(string search) {
    ll L = 1, R = maks;

    while (L <= R) {
        // cout << L << " " << R << endl;
        if (L == R) return L;

        ll mid = (L + R) / 2;
        ll val = hitung(mid);

        if (val < M) L = mid + 1;
        else if (val > M) R = mid - 1;
        else {
            // ini kalo hitung(mid) nya jatuh pas
            // di interval yang mau kita cari
            if (search == "kiri") {
                // kalo ternyata yang mid sekarang
                // adalah batas kiri yang kita cari
                // ya return mid nya aja sebagai batas kiri
                if (hitung(mid - 1) != M) return mid;
                // kalo ternyata engga, geser pointer
                // yang kanan jadi mid - 1
                else R = mid - 1;
            }
            else if (search == "kanan") {
                // kalo ternyata yang mid sekarang
                // adalah batas kanan yang kita cari
                // ya return mid nya aja sebagai batas kanan
                if (hitung(mid + 1) != M) return mid;
                // kalo ternyata engga, geser pointer
                // yang kiri jadi mid + 1
                else L = mid + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // maks = maks * 2;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    bool ada = check0();
    if (!ada) {
        cout << 0 << endl;
        return 0;
    }

    // cek dulu apa ternyata 1 itu batas kiri
    if (hitung(1) == M) kiri = 1;
    else kiri = cari("kiri");
    // cout << kiri << endl;

    // cek dulu apa ternyata 2^63 - 1 itu batas kanan
    if (hitung(maks + 1) == M) kanan = maks;
    else kanan = cari("kanan");
    // cout << kanan << endl;

    cout << kanan + 1 - kiri << endl;

    return 0;
}