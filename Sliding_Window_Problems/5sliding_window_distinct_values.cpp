// CSES Sliding Window Problem 5
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr, int n, int k)
{
    vector<int> res;
    unordered_map<int, int> mp;
    int i = 0, j = 0;
    while (i < k)
    {
        mp[arr[i]]++;
        i++;
    }
    res.push_back(mp.size());
    while (i < n)
    {
        mp[arr[j]]--;
        if (mp[arr[j]] == 0)
            mp.erase(arr[j]);
        j++;
        mp[arr[i]]++;
        i++;
        res.push_back(mp.size());
    }
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = solve(arr, n, k);
    for (int it : res)
        cout << it << " ";
    return 0;
}