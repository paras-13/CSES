// CSES Sliding Window Problem 1
#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int> &arr, int n, int k)
{
    int i = 0, j = 0;
    long long sum = 0;
    while (i < k)
    {
        sum += 0ll + arr[i];
        i++;
    }
    long long res = sum;
    while (i < n)
    {
        sum -= arr[j];
        j++;
        sum += arr[i];
        i++;
        res ^= sum;
    }
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++)
        arr[i] = ((1ll * arr[i - 1] * a) % c + b) % c;

    cout << solve(arr, n, k) << endl;
}