#include <bits/stdc++.h>
#define pq priority_queue
using namespace std;

int N, command, inp;

void iosbase() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct cmp{
    bool operator()(const int a, const int b){
        return a < b;
    }
};

pq< int, vector<int>, cmp > Q;

int main() {
    iosbase();

    cin >> N;
    while(N--) {
        cin >> command;

        if (command == 1) {
            cin >> inp;
            Q.push(inp);
        }
        else if (command == 2) {
            if (Q.size() > 0) cout << Q.top() << endl;
        }
        else if (command == 3) {
            Q.pop();
        }
    }
}