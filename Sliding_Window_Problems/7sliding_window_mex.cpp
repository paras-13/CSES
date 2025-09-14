// CSES Sliding Window MEX Problem 7
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &arr, int n, int k)
{
    unordered_map<int, int> freq;
    vector<int> res;
    set<int> st;
    for (int i = 0; i <= n + 1; i++)
        st.insert(i);
    int i = 0, j = 0;
    while (i < k)
    {
        freq[arr[i]]++;
        if (freq[arr[i]] == 1)
            st.erase(arr[i]);
        i++;
    }
    res.push_back(*st.begin());
    while (i < n)
    {
        freq[arr[j]]--;
        if (freq[arr[j]] == 0)
            st.insert(arr[j]);
        j++;
        freq[arr[i]]++;
        st.erase(arr[i]);
        res.push_back(*st.begin());
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
}