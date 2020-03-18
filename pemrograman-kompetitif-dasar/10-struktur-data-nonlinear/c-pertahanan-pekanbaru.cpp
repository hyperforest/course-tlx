#include <bits/stdc++.h>
#define ll long long
#define append push_back
using namespace std;

const ll md = 1000000007;
const int MX = 300000;
const ll INF = (1LL << 63) - 1;

string label;
ll N, Sd, Sm;
ll P[MX + 5], K[MX + 5], L[MX + 5];
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> label;
    cin >> N >> Sd >> Sm;
    for (int i = 1; i <= N - 1; i++) {
        cin >> P[i] >> K[i] >> L[i];
    }
    P[N] = Sm;

    for (int i = 1; i <= N; i++) {
        if (P[i] > Sd + i - 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> sorted;
    priority_queue<int> Q;
    int snow = Sd;

    for (int i = 1; i <= N - 1; i++) {
        if (snow < P[i]) {
            while (snow < P[i]) {
                ans -= Q.top();
                Q.pop();
                snow += 1;
            }
        }

        if (L[i] <= K[i]) {
            ans += L[i];
            snow += 1;
        }
        else {
            Q.push(K[i] - L[i]);
            ans += K[i];
        }
        // cout << snow << " " << ans << endl;
    }
    // cout << snow << endl;
    if (snow < Sm) {
        while (snow < Sm) {
            ans -= Q.top();
            Q.pop();
            snow += 1;
        }
    }

    cout << ans << endl;
    return 0;
}
