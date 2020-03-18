#include <bits/stdc++.h>
#define ii pair<int, int>
#define mp make_pair
#define cf Q.front().first
#define cs Q.front().second
using namespace std;

int A[40][40], ans, M, N, color, B, K;
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
            int x = dx[i], y = dy[i];
            if (!valid(r + x, c + y)) continue;

            if (A[r + x][c + y] == color and !pernah[r + x][c + y]) {
                Q.push({r + x, c + y});
                pernah[r + x][c + y] = true;
            }
        }
    }
}

void DFS(int r, int c) {
   pernah[r][c] = true;
   ans++;

   for (int i = 0; i < 4; i++) {
        int x = dx[i], y = dy[i];
        if (!valid(r + x, c + y)) continue;

        if (A[r + x][c + y] == color and !pernah[r + x][c + y]) {
            pernah[r + x][c + y] = true;
            DFS(r + x, c + y);
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
    
    cin >> B >> K;
    color = A[B][K];
    
    DFS(B, K);
    cout << ans * (ans - 1) << endl;
}