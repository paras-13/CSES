// CSES Graph Problem 9
#include <bits/stdc++.h>
#define P pair<int, long long>
#define INF LLONG_MAX
using namespace std;
class Graph
{
private:
    vector<vector<P>> adj;
    vector<vector<long long>> dist;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
        adj.resize(v + 1);
        dist.resize(v + 1, vector<long long>(v + 1, INF));
        for (int i = 1; i <= v; ++i)
        {
            dist[i][i] = 0;
        }
    }
    void addEdge(int u, int v, long long w)
    {
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    void all_pairs_shortest_path()
    {
        for (int k = 1; k <= v; k++)
        {
            for (int i = 1; i <= v; i++)
            {
                for (int j = 1; j <= v; j++)
                {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > (dist[i][k] + dist[k][j]))
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    long long getShortestPath(int u, int v)
    {
        return dist[u][v] == INF ? -1 : dist[u][v];
    }
};

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    Graph g1(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g1.addEdge(u, v, w);
    }
    g1.all_pairs_shortest_path();
    while (q--)
    {
        int source, dest;
        cin >> source >> dest;
        cout << g1.getShortestPath(source, dest) << "\n";
    }
    return 0;
}