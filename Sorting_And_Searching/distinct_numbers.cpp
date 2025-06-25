#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            cnt++;
    }
    return cnt;
}
int main()
{
    int n, val;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << solve(v, n);
    return 0;
}