// CSES Graph Algorithm Problem 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define P pair<int, int>
using namespace std;
vector<P> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
string path = "URDL";
vector<vector<pair<int, string>>> dp;

pair<int, string> solve(vector<vector<char>> &matrix, int n, int m, int sx, int sy, int fx, int fy)
{
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<P> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = dir[i].first + x;
            int col = dir[i].second + y;
            if (row < 0 || col < 0 || row >= n || col >= m)
                continue;
            if (matrix[row][col] == '#')
                continue;
            if (dist[row][col] > dist[x][y] + 1)
            {
                dist[row][col] = dist[x][y] + 1;
                d[row][col] = i;
                q.push({row, col});
            }
        }
    }

    if (dist[fx][fy] == INT_MAX)
        return {INT_MAX, ""};

    string str;
    int x = fx, y = fy;
    while (x != sx || y != sy)
    {
        int id = d[x][y];
        str.push_back(path[id]);
        x -= dir[id].first;
        y -= dir[id].second;
    }
    return {dist[fx][fy], str};
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    dp.resize(n, vector<pair<int, string>>(m, {-1, ""}));
    int sx, sy, fx, fy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            if (matrix[i][j] == 'B')
            {
                fx = i;
                fy = j;
            }
        }
    }

    auto path = solve(matrix, n, m, sx, sy, fx, fy);
    reverse(path.second.begin(), path.second.end());
    if (path.first != INT_MAX)
        cout << "YES\n"
             << path.first << endl
             << path.second;
    else
        cout << "NO";
}