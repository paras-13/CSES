// TrailingZeroes
// Problem link -- > https://cses.fi/problemset/task/1618
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int sum = 0;
	while(n >= 5) {
		sum += n/5;
		n /= 5;
	}
	cout << sum << endl;
}