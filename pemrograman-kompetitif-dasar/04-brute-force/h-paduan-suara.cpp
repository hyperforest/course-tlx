#include <bits/stdc++.h>
#define ll long long
#define append push_back
using namespace std;

const ll md = 1000000007;
ll M, N;
int A[10010];

ll H, S;
vector<int> ans, batas;
string biner;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i];
    }
    cin >> N;

    // misal S = M % N, H = M / N
    // ada S grup yang dapet H + 1 orang
    // N - S grup sisanya dapet H orang
    H = M / N;
    S = M % N;
    sort(A + 1, A + M + 1);

    if (S == 0) {
        for (int i = 1; i <= M; i++) {
            if (i % H == 0) ans.push_back(A[i] + 1);
            if (ans.size() == N - 1) break;
        }

        for (int i = 0; i < N - 1; i++) {
            cout << ans[i];
            if (i == N - 1) cout << endl;
            else cout << " ";
        }

        return 0;
    }

    for (int i = 1; i < (1LL << N); i++) {
        int n = i, cnt1 = 0, prev = 0;
        batas.clear();
        biner = "";

        for (int i = 1; i <= N; i++) {
            if (n % 2 == 0) biner = "0" + biner;
            else {biner = "1" + biner; cnt1 += 1;}
            n /= 2;
        }

        if (cnt1 != S) continue;
        // cout << biner << endl;

        for (int i = 0; i < N; i++) {
            if (biner[i] == '0') {
                prev += H;
                batas.append(prev);
            }
            else {
                prev += (H + 1);
                batas.append(prev);
            }
            if (batas.size() == N - 1) break;
        }

        for (int i = 0; i < batas.size(); i++) {
            if (A[batas[i]] == A[batas[i] + 1]) {
                ans.clear();
                break;
            }
            ans.append(A[batas[i]] + 1);
        }

        if (ans.size() == N - 1) break;
    }

    for (int i = 0; i < N - 1; i++) {
        cout << ans[i];
        if (i == N - 2) cout << endl;
        else cout << " ";
    }

    return 0;
}

/*
8
21 22 24 26 26 28 211 500
5

20
1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39
*/