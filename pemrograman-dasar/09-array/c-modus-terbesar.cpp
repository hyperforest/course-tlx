#include <bits/stdc++.h>
using namespace std;

int rate[1001]; //buat nyimpen rate munculnya
int main() {
    int N, a, maxrate = 0, maxel = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a;
        rate[a]++;
    }

    for(int i = 0; i < 1001; i++) {
        if(rate[i] >= maxrate) {
            if(i > maxel) {
                maxrate = rate[i];
                maxel = i;
            }
        }
    }

    cout << maxel << endl;
}