/**
    "Indeed, with every hardship comes ease" (Qur'an 94:6)

    * Template *
    Author : Rimba Erlangga
**/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define REPP(i, a, b) for(int i = (a); i < (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.end(), a.begin()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))
#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vl vector<ll>
#define mat vector<vl>
#define append push_back

// permanent constant
const int md = 1000000007;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MX = 200;
const ll inf = 1e9;

ll adj[MX + 5][MX + 5];
ll P[MX + 5];
ll V, E, Q;

ll min(ll a, ll b) {
    if (a < b) return a;
    return b;
}

void reset(int V) {
    for (int i = 0; i <= V; i++)  {
        for (int j = 0; j <= V; j++) {
            if (i != j) adj[i][j] = inf;
        }
    }
}

void floyd(int V) {
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++)  {
            for (int j = 1; j <= V; j++) {        
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V >> E >> Q;
    reset(V);

    REP(i, 1, E) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = min(w, adj[u][v]);
        adj[v][u] = min(w, adj[v][u]);
    }

    floyd(V);

    if (Q == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    for (int i = 1; i <= Q; i++) {
        cin >> P[i];
    }
    for (int i = 1; i < Q; i++) {
        ans += adj[P[i]][P[i + 1]];
    }
    cout << ans << endl;

    return 0;
}