// CSES Sliding Window Problem 3
#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int> &arr, int n, int k)
{
    int i = 1, j = 0;
    long long Xor = arr[0];
    while (i < k)
    {
        Xor ^= arr[i];
        i++;
    }
    long long res = Xor;
    while (i < n)
    {
        Xor ^= arr[j];
        j++;
        Xor ^= arr[i];
        i++;
        res ^= Xor;
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