// CSES Graph Algorithms, Problem 4
#include <bits/stdc++.h>
#define P pair<int, int>
#define INF 1e9
using namespace std;
class Graph
{
private:
    int V;
    vector<vector<int>> adj;
    vector<int> dist;
    vector<int> parent;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V + 1);
        dist.resize(V + 1, INF);
        parent.resize(V + 1);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int getPathLen()
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({1, 1});
        dist[1] = 1;
        parent[1] = 1;
        while (!pq.empty())
        {
            auto [weight, node] = pq.top();
            pq.pop();
            if (dist[node] != weight)
                continue;
            for (int edge : adj[node])
            {
                if (dist[edge] > dist[node] + 1)
                {
                    dist[edge] = dist[node] + 1;
                    pq.push({dist[edge], edge});
                    parent[edge] = node;
                }
            }
        }
        return dist[V];
    }
    vector<int> getPath()
    {
        vector<int> path;
        int node = V;
        while (node != parent[node])
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(node);
        reverse(path.begin(), path.end());
        return path;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    Graph g1(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g1.addEdge(u, v);
    }
    int pathLen = g1.getPathLen();
    if (pathLen == INF)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << pathLen << "\n";
        vector<int> path = g1.getPath();
        for (int it : path)
            cout << it << " ";
    }
    return 0;
}