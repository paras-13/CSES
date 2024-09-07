// Problem Link --> https://cses.fi/problemset/task/1754
#include <iostream>
#include <algorithm>
#define ll long long
#define nl "\n"
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
		if((a+b)%3 == 0) {
			if(max(a, b) <= min(a, b)*2)
				cout << "YES" << nl;
			else
				cout << "NO" << nl;
		}
		else
			cout << "NO" << nl;
	}
}
