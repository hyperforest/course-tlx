#include <bits/stdc++.h>
using namespace std;

int N, X;
int arr[1005];

int main() {
    cin >> N >> X;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int mins = 10000000;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (abs(X - arr[i]) < mins) {
            mins = abs(X - arr[i]);
            ans = arr[i];
        }
        else if (abs(X - arr[i]) == mins) {
            if (arr[i] < ans) {
                ans = arr[i];
            }
        }
    }

    cout << ans << endl;
}