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

double x1, y5, x2, y2, x3, y3, x4, y4;
int T;

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    long long cross(const Point &p) const { return x * p.y - y * p.x; }
    long long cross(const Point &a, const Point &b) const { return (a - *this).cross(b - *this); }
};

struct Segment {
    Point A, B;
};

int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(double a, double b, double c, double d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool segment_intersection(const Segment &s, const Segment &t) {
    Point a = s.A, b = s.B, c = t.A, d = t.B;

    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> x1 >> y5 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Segment a = {{x1, y5}, {x1, y2}};
        Segment b = {{x1, y2}, {x2, y2}};
        Segment c = {{x2, y2}, {x2, y5}};
        Segment d = {{x2, y5}, {x1, y5}};
        Segment s = {{x3, y3}, {x4, y4}};
        
        bool intersecting = false;
        intersecting = (intersecting or segment_intersection(a, s));
        intersecting = (intersecting or segment_intersection(b, s));
        intersecting = (intersecting or segment_intersection(c, s));
        intersecting = (intersecting or segment_intersection(d, s));

        if (intersecting) cout << "YA\n";
        else cout << "TIDAK\n";
    }
    
    return 0;
}