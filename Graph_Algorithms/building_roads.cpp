// CSES Graph Algorithm Problem 3
#include <iostream>
#include <vector>
using namespace std;
class DisjointSet
{
public:
    vector<int> rank;
    vector<int> parent;
    int n;
    DisjointSet(int n)
    {
        this->n = n;
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV)
            return;
        if (rank[parentU] > rank[parentV])
            parent[parentV] = parentU;
        else if (rank[parentV] > rank[parentU])
            parent[parentU] = parentV;
        else
        {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    DisjointSet ds(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ds.unionByRank(u, v);
    }
    vector<int> places;
    for (int i = 1; i <= n; i++)
    {
        if (ds.findParent(i) == i)
            places.push_back(i);
    }
    cout << places.size() - 1 << endl;
    for (int i = 0; i < places.size() - 1; i++)
        cout << places[i] << " " << places[i + 1] << endl;
}
