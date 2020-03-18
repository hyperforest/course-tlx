#include <bits/stdc++.h>
#define ll long long
#define append push_back
using namespace std;

struct Point {
    long double x, y;
};

long double triangle_area(Point P, Point Q, Point R) {
    long double ans = 0.0;
    long double x1 = P.x, y1 = P.y;
    long double x2 = Q.x, y2 = Q.y;
    long double x3 = R.x, y3 = R.y;
    
    ans += (x1 * y2 - x2 * y1);
    ans += (x2 * y3 - x3 * y2);
    ans += (x3 * y1 - x1 * y3);
    
    return fabs(ans) / 2.0;
}

const long double INF = (1LL << 63) - 1;
int N, cnt;
Point P[305];
long double ans = INF;

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // cout << ans << endl;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        long double x, y; cin >> x >> y;
        P[i].x = x; P[i].y = y;
    }

    if (N < 3) {
        cout << "-1.00" << endl;
        return 0;
    }

    for (int i = 1; i <= N - 2; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            for (int k = j + 1; k <= N; k++) {
                // cout << i << " " << j << " " << k << endl;
                long double A = triangle_area(P[i], P[j], P[k]);
                // cout << A << endl;

                if (A == 0) continue; // kalo kolinear / segaris
                if (A < ans) {
                    ans = A;
                    cnt = 1;
                }
                else if (A == ans) cnt += 1;
            }
        }
    }

    if (ans == INF) cout << "-1.00" << endl;
    else if (cnt != 1) cout << "-1.00" << endl;
    else printf("%.2Lf\n", ans);
    return 0;
}