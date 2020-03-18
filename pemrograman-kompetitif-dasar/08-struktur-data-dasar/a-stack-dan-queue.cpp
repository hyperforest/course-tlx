#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll md = 1000000007;

list<int> P;
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    while (N--) {
        string cmd; cin >> cmd;
        int X;

        if (cmd == "push_back") {
            cin >> X; P.push_back(X);
        }
        else if (cmd == "push_front") {
            cin >> X; P.push_front(X);
        }
        else if (cmd == "pop_front") {
            P.pop_front();
        }
        else if (cmd == "pop_back") {
            P.pop_back();
        }
    }

    list<int>::iterator it;
    for (it = P.begin(); it != P.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
