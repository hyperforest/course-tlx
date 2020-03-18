/**
    "Indeed, with every hardship comes ease" (Qur'an 94:6)

    * Template *
    Author : Rimba Erlangga
**/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define REPP(i, a, b) for(int i = (a); i < (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.end(), a.begin()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))
#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vl vector<ll>
#define mat vector<vl>
#define append push_back

// permanent constant
const int md = 1000000007;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

double x, y, r1, p, q, r2;

struct Point {
    double x, y;
};

struct Circle {
    Point O; double r;
};

string is_intersecting(Circle A, Circle B) {
    double x = A.O.x, y = A.O.y, p = B.O.x, q = B.O.y;
    double r1 = A.r, r2 = B.r;

    // kedua lingkaran sama
    if (x == p and y == q and r1 == r2) return "sama";

    // satu lingkaran di dalam lingkaran lainnya, dan tidak bersinggungan
    if (sqrt((x - p) * (x - p) + (y - q) * (y - q)) < abs(r1 - r2)) {
        return "terpisah di dalam";
    }

    // satu lingkaran di dalam lingkaran lainnya, dan bersinggungan
    if (sqrt((x - p) * (x - p) + (y - q) * (y - q)) == abs(r1 - r2)) {
        return "bersinggungan di dalam";
    }

    // tidak berpotongan
    if ((x - p) * (x - p) + (y - q) * (y - q) > (r1 + r2) * (r1 + r2)) {
        return "terpisah di luar";
    }

    // bersinggungan
    if ((x - p) * (x - p) + (y - q) * (y - q) == (r1 + r2) * (r1 + r2)) {
        return "bersinggungan";
    }

    if ((x - p) * (x - p) + (y - q) * (y - q) < (r1 + r2) * (r1 + r2)) {
        return "berpotongan";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> x >> y >> r1;
    cin >> p >> q >> r2;

    Circle A = {{x, y}, r1};
    Circle B = {{p, q}, r2};
    string status = is_intersecting(A, B);
    
    if (status == "terpisah di luar" or status == "terpisah di dalam") {
        cout << "tidak bersentuhan\n";
    }
    else cout << "bersentuhan\n";

    return 0;
}