// CSES Sliding Window Problem 6
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &arr, int n, int k)
{
    vector<int> res;
    unordered_map<int, int> freq;
    unordered_map<int, set<int>> mp;
    int i = 0, j = 0, maxi = 0;
    while (i < k)
    {
        freq[arr[i]]++;
        maxi = max(maxi, freq[arr[i]]);
        mp[freq[arr[i]]].insert(arr[i]);
        i++;
    }
    res.push_back(*mp[maxi].begin());
    while (i < n)
    {
        int fq = freq[arr[j]];
        mp[fq].erase(arr[j]);
        if (mp[maxi].size() == 0)
        {
            mp.erase(maxi);
            maxi--;
        }
        freq[arr[j]]--;
        j++;

        freq[arr[i]]++;
        maxi = max(maxi, freq[arr[i]]);
        mp[freq[arr[i]]].insert(arr[i]);
        res.push_back(*mp[maxi].begin());
        i++;
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