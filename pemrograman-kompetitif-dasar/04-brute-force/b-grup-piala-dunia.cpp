#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll md = 1000000007;

ll T, N;
vector<vector<int> > P[7];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // generate all possibilities
    for (int n = 2; n <= 5; n++) {
        int L = n * (n - 1) / 2;
        int C = pow(3, L);

        // generate all win-lose conditions
        for (int i = 0; i < C; i++) {
            string S = "";
            int m = i;
            for (int it = 1; it <= L; it++) {
                S = (char) ('0' + (m % 3)) + S;
                m /= 3;
            }

            vector<int> score(n);
            for (int it = 0; it < n; it++) score[it] = 0;

            int ptr = 0;
            for (int it = 0; it < n - 1; it++) {
                for (int jt = it + 1; jt < n; jt++) {
                    if (S[ptr] == '0') score[jt] += 3;
                    else if (S[ptr] == '2') score[it] += 3;
                    else {score[it] += 1; score[jt] += 1;}
                    ptr += 1;
                }
            }

            P[n].push_back(score);
        }
    }

    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> score(N);
        for (int i = 0; i < N; i++) {
            cin >> score[i];
        }

        bool ada = false;
        for (int i = 0; i < P[N].size(); i++) {
            if (P[N][i] == score) {
                cout << "YES\n";
                ada = true; break;
            }
        }

        if (!ada) cout << "NO\n";
    }

    return 0;
}
