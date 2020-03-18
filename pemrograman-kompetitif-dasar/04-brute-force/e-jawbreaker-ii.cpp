#include <bits/stdc++.h>
#define ii pair<int, int>
#define mp make_pair
#define cf Q.front().first
#define cs Q.front().second
using namespace std;

int A[40][40], ans, M, N, color, B, K, maks;
bool pernah[40][40];
queue<ii> Q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int r, int c) {
    return (0 <= r and r < M and 0 <= c and c < N);
}

void BFS(int r, int c) {
    Q.push(mp(r, c));
    pernah[r][c] = true;

    while(!Q.empty()){
        r = Q.front().first;
        c = Q.front().second;
        Q.pop();
        // cout << r << " " << c << endl;
        ans++;

        for (int i = 0; i < 4; i++) {
            int x = r + dx[i], y = c + dy[i];
            if (!valid(x, y)) continue;

            if (A[x][y] == color and !pernah[x][y]) {
                Q.push({x, y});
                pernah[x][y] = true;
            }
        }
    }
}

void DFS(int r, int c) {
   pernah[r][c] = true;
   ans++;

   for (int i = 0; i < 4; i++) {
        int x = r + dx[i], y = c + dy[i];
        if (!valid(x, y)) continue;

        if (A[x][y] == color and !pernah[x][y]) {
            pernah[x][y] = true;
            DFS(x, y);
        }
    }
}

int main() {
    cin >> M >> N;
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!pernah[i][j]) {
                color = A[i][j];
                DFS(i, j);
            }
            maks = max(maks, ans * (ans - 1));
            ans = 0;
        }
    }

    cout << maks << endl;
} 