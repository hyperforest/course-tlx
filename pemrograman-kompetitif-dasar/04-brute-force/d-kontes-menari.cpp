#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll md = 1000000007;

ll N, R, Y, J, H;
ll D[15];
char T[15];
string header;

ll sumK, ans, ptr = 1;
ll score[3800000];
bool pernah[16];
bool yaqueen; // buat flag apa ada move yg meyakinkan

void brute(int depth, vector<int> perm);
ll binser(ll L, ll R) {
    // fungsi binary search buat mencari
    // index pertama i shg score[i] > H
    ll mid;

    while (L <= R) {
        mid = (L + R) / 2;

        if (score[mid] <= H) L = mid + 1;
        else {
            if (score[mid - 1] <= H) return mid;
            else R = mid - 1;
        }
    }

    return L;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> header; cin >> header;
    cin >> N >> R >> Y >> J;
    for (int i = 1; i <= N; i++) {
        cin >> D[i] >> T[i];
    }

    vector<int> kosongan; kosongan.clear();
    brute(0, kosongan);

    ptr -= 1;
    sort(score + 1, score + ptr + 1);

    // for (int i = 1; i <= ptr; i++) {
    //     cout << "> " << score[i] << endl;
    // }

    while (J--) {
        cin >> H;
        
        if (score[1] > H) cout << ptr << endl;
        else if (score[ptr] < H) cout << 0 << endl;
        else cout << ptr + 1 - binser(1, ptr) << endl;
    }

    return 0;
}

void brute(int depth, vector<int> perm) {
    if (depth == R) {
        char sebelum = 'X';
        sumK = 0;
        yaqueen = false;
        for (int i = 0; i < depth; i++) {
            int move = perm[i];

            // cout << move << " ";

            ll K = D[move];
            if (T[move] == 'Y') yaqueen = true;
            if (sebelum == 'P') K = K * 2;
            else if (sebelum == 'L') K = K / 2;
            if (yaqueen) K += Y;

            // cout << K << endl;
            sumK += K;
            sebelum = T[move];
        }
        // cout << endl;

        if (yaqueen) sumK -= Y;
        // untuk kompensasi + Y ketika
        // pertama kali ketemu move meyakinkan
        
        // cout << ">>> " << sumK << endl;

        score[ptr] = sumK;
        ptr += 1;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!pernah[i]) {
            pernah[i] = true;
            perm.push_back(i);
            brute(depth + 1, perm);
            perm.pop_back();
            pernah[i] = false;
        }
    }
}