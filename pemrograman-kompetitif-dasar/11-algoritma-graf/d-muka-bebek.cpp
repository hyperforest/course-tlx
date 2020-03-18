#include <bits/stdc++.h>
#define ll long long
#define append push_back
using namespace std;

struct edge {
    ll a, b, w; 
};

ll N, ans;
ll adj[105][105];
ll rep[5005];
vector<edge> v;

bool cmp(edge e1, edge e2);
void Read();
void Init();
bool Check(int a, int b);
ll Find(int x);
void Join(int a, int b);
void Exe();

int main() {
    Read();
    Init();
    Exe();
}

bool cmp(edge e1, edge e2) {
    return e1.w < e2.w;
}

void Read() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }
}

void Init() {
    for(int i = 0; i < N-1; i++) {
        for(int j = i+1; j < N; j++) {
            v.append({i, j, adj[i][j]});
        }
    }

    for(int i = 0; i < 5005; i++) rep[i] = i;
}

bool Check(int a, int b) {
    return Find(a) == Find(b);
}

ll Find(int x) {
    if (rep[x] == x) return x;
    rep[x] = Find(rep[x]);
    return rep[x];
}

void Join(int a, int b) {
    ll repA = Find(a);
    ll repB = Find(b);
    rep[repA] = repB;
}

void Exe() {
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) {
        ll a = v[i].a, b = v[i].b, w = v[i].w;
        if(!Check(a, b)) {
            ans += w;
            Join(a, b);
        }
    }
    cout << ans << endl;
}