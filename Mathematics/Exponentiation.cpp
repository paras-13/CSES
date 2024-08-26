// CSES question link --> https://www.cses.fi/problemset/task/1095/
#include <iostream>
#define ll long long 
#define mod 1000000007
using namespace std;
ll power(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if(b & 1)
            res = (res * a)%mod;
        b >>= 1;
        a = (a*a)%mod;
    }
    return res%mod;
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        ll a, b;
        cin >> a >> b;
        ll ans = power(a, b);
        cout << ans << endl;
    }
    return 0;
}