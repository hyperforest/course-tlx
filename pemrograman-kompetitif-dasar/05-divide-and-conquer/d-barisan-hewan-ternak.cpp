#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll a[100005], cf[100005];
    
int main(){
    cin >> N;
    
    cin >> a[1];
    cf[1] = a[1];
    for(int i = 2; i <= N; i++) {
        cin >> a[i];
        cf[i] = a[i]+cf[i-1];
    }
    
    ll Q;
    cin >> Q;
    
    while(Q--) {
        ll k, ans = -1;
        cin >> k;
        ll left = 1, right = N;
        bool found = false;
        
        while(left <= right) {
            ll mid = (left+right)/2;
//          cout << left << " " << mid << " " << right << endl;
            
            if((cf[mid-1] < k && k <= cf[mid]) || left == right) {
                ans = mid;
                found = true;
                break;
            }
            else if(k <= cf[mid-1]) right = mid-1;
            else left = mid+1;
        }
        
        cout << ans << endl;
    }
}