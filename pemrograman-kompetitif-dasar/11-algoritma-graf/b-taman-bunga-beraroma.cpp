#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define append push_back
using namespace std;

struct edge {
    ll u, v, w;
};

const ll inf = 1e9;

edge EL[1005];
ll dist[505];
int T, V, E;

int Bellman() {
    for (int i = 0; i < V; i++)
        dist[i] = inf;

    dist[0] = 0;

    int flag = -1;
    for (int i = 0; i <= V - 1; i++) {
        flag = -1;
        for (int k = 0; k < E; k++) {
            ll u = EL[k].u, v = EL[k].v, w = EL[k].w;

            if (dist[u] < inf) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = max(-inf, dist[u] + w);
                    flag = 0;
                }
            }
        }
    }

    return flag;
}

int main() {
    cin >> T;

    while (T--) {
        cin >> V >> E;

        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            EL[i] = {u, v, w};
        }

        if (Bellman() != -1) cout << "Pak Dengklek tidak mau pulang\n";
        else if (dist[V - 1] == inf) cout << "Tidak ada jalan\n";
        else cout << dist[V - 1] << endl;
    }
}