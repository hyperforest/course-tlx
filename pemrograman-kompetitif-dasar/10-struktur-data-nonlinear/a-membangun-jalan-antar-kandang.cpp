#include <bits/stdc++.h>
using namespace std;

void init(int N);
void join(int a, int b);
int find(int x);
bool check(int a, int b);

int N, Q;
int par[100005];

int main() {
    cin >> N >> Q;
    init(N);

    while (Q--) {
        int c, a, b;
        cin >> c >> a >> b;

        if (c == 1) join(a, b);
        else if (check(a, b)) printf("Y\n");
        else printf("T\n");
    }
}

void init(int N) {
    for(int i = 1; i <= N; i++)
        par[i] = i;
}

void join(int a, int b) {
    int repA = find(a);
    int repB = find(b);
    par[repA] = repB;
}

int find(int x) {
    if (par[x] == x) return x;
    par[x] = find(par[x]);
    return par[x];
}

bool check(int a, int b) {
    return find(a) == find(b);
}