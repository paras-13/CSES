// After multiple operation value of n may cross 10^9 constraint so we have to use long long at its declaration
// Rest all is easy
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    while(n != 1) {
        cout << n << " ";
        if(n & 1)   n = n*3 + 1;
        else n/=2;
    }
    cout << n;
    return 0;
}