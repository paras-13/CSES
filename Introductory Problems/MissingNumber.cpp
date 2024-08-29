// Problem link --> https://cses.fi/problemset/task/1083
#include <iostream>
using namespace std;
int main() {
    long long n, val;
    cin >> n;
    long long sum = 0;
    for(int i=0; i<n-1; i++){
        cin >> val;
        sum += val;
    }
    long long orgSum = (n*(n+1))/2;
    cout << orgSum - sum << endl;
}