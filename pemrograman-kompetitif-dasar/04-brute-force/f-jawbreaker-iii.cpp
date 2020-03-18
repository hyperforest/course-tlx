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

void read() {
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

void find_max() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(!pernah[i][j]) {
                color = A[i][j];
                DFS(i, j);
            }
            if(ans > maks) {
                B = i;
                K = j;
                maks = ans;
            }
            ans = 0;
        }
    }
}

void empty(int r, int c) {
    // mengosongkan petak yang diklik
    int temp = A[r][c];
    A[r][c] = 0;

    for (int i = 0; i < 4; i++) {
        int x = dx[i], y = dy[i];
        if (!valid(r + x, c + y)) continue;
        if (A[r + x][c + y] == temp) empty(r + x, c + y);
    }
}

void runtuhkan() {
    for(int k = 0; k < N; k++){
        for(int i = 0; i < M; i++){
            if (A[i][k] == 0) {
                int cur = i, temp = A[i][k];
                while (cur > 0) {
                    A[cur][k] = A[cur-1][k];
                    cur--;
                }
                A[0][k] = 0;
            }
        }
    }
}

void print() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if (A[i][j] == 0) cout << ".";
            else cout << A[i][j];
            if (j < N - 1) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    read();
    find_max();
    empty(B, K);
    runtuhkan();
    print();
} 