// CSES Graph Problem 8
#include <bits/stdc++.h>
#define nl '\n'
#define mod 1000000007
#define int long long
#define P pair<int, int>
using namespace std;
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<P>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<int> dist(n + 1, LLONG_MAX);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        auto [wt, node] = pq.top();
        pq.pop();
        if (dist[node] != wt)
            continue;
        for (auto [e, w] : adj[node])
        {
            if (dist[e] > dist[node] + w)
            {
                dist[e] = dist[node] + w;
                pq.push({dist[e], e});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    return 0;
}