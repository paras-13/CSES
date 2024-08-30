// Bit Strings
// Problem link -- > https://cses.fi/problemset/task/1617
#include <iostream>
#define mod 1000000007
using namespace std;
long long power(long long n, int x) {
	long long res = 1;
	while(x > 0) {
		if(x&1)
			res = (res * n)%mod;
		n = (n*n)%mod;
		x >>= 1;
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	long long ans =  power(2, n);
	cout << ans << endl;
}