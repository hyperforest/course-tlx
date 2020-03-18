#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define mp make_pair
#define cf Q.front().first
#define cs Q.front().second
using namespace std;

ll A[40][40], S[40][40];
ll ans, M, N, color, B, K, maks;
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
            S[i][j] = A[i][j];
        }
    }
}

void empty(int r, int c) {
    // mengubah petak yang diklik dan
    // sekitarnya menjadi 0
    int temp = A[r][c];
    A[r][c] = 0;

    for (int i = 0; i < 4; i++) {
        int x = dx[i], y = dy[i];
        if (!valid(r + x, c + y)) continue;
        if (A[r + x][c + y] == temp) empty(r + x, c + y);
    }
}

void runtuhkan() {
    // note: dibikin empty dulu sebelum diruntuhin
    for(int k = 0; k < N; k++){
        for(int i = 0; i < M; i++){
            if (A[i][k] == 0) {
                int cur = i;
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

void reset_pernah() {
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 40; j++) 
            pernah[i][j] = false;
}

void reset_papan() {
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 40; j++) 
            A[i][j] = S[i][j];
}

int main() {
    read();

    for (int i1 = 0; i1 < M; i1++) {
        for (int j1 = 0; j1 < N; j1++) {
            ll total = 0;
            ans = 0;

            if (!pernah[i1][j1]) {
                color = A[i1][j1];
                BFS(i1, j1);
                empty(i1, j1);
            }
            if (ans > 1) runtuhkan();

            reset_pernah();
            total = ans * (ans - 1);
            // cout << total << endl;

            // print();

            // step 2
            for (int i2 = 0; i2 < M; i2++) {
                for (int j2 = 0; j2 < N; j2++) {
                    if (i1 == i2 and j1 == j2) continue;
                    if (A[i2][j2] == 0) continue;

                    ans = 0;
                    if (!pernah[i2][j2]) {
                        color = A[i2][j2];
                        BFS(i2, j2);
                    }

                    // cout << i2 << " " << j2 << " " << ans * (ans - 1) << endl;
                    maks = max(maks, total + ans * (ans - 1));
                }

                // cout << "---\n";
                // print();
            }

            // cout << endl;
            maks = max(maks, total);
            reset_papan();
            reset_pernah();
        }
    }
    
    cout << maks << endl;
} 