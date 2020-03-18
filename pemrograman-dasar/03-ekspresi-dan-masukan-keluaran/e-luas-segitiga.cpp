#include <iostream>
using namespace std;

double a,t;
int main() {
    cin >> a >> t;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << a*t/2 << endl;
}