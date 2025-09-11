// CSES Sliding Window Problem 2
#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;
long long solve(vector<int> &arr, int n, int k)
{
    deque<P> dq;
    int i = 0;
    while (i < k)
    {
        while (!dq.empty() && dq.back().first > arr[i])
            dq.pop_back();
        dq.push_back({arr[i], i});
        i++;
    }
    long long res = dq.front().first;
    while (i < n)
    {
        if (dq.front().second + k <= i)
            dq.pop_front();
        while (!dq.empty() && dq.back().first > arr[i])
            dq.pop_back();
        dq.push_back({arr[i], i});
        res ^= dq.front().first;
        i++;
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

    cout << solve(arr, n, k);
}