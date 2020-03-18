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

const int MX = 5000;
const ll inf = 1e9;

int V, E, a, b;

ll dist[MX + 5]; // dist[v] = jarak dari vertex source ke vertex v
bool vis[MX + 5];
ll pred[MX + 5]; // pred[v] = predecessor dari vertex v di shortest path

vector<pair<ll, ll> > adj[MX + 5];

void reset(int N) {
    for (int i = 0; i <= N; i++) {
        dist[i] = inf;
        vis[i] = false;
        pred[i] = -1;
    }
}

void dijkstra(int s) {
    // hitung shortest path dari vertex s ke semua vertex lain
    // simpen di array dist
    dist[s] = 0;

    while (true) {
        int u = -1;
        ll mins = inf;

        for (int i = 1; i <= V; i++) {
            // cari node yg belum dikunjungi dgn dist terkecil
            if (!vis[i] and dist[i] < mins) {
                u = i; mins = dist[i];
            }
        }

        if (u == -1 or dist[u] == inf) break;

        vis[u] = true;
        for (int i = 0; i < adj[u].size(); i++) {
            ll v = adj[u][i].first;
            ll w = adj[u][i].second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }
}

// permanent constant
const int md = 1000000007;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V >> E >> a >> b;

    reset(V);

    for (int i = 1; i <= E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].append({v, w});
        adj[v].append({u, w});
    }

    dijkstra(a);
    cout << dist[b] << endl;

    return 0;
}