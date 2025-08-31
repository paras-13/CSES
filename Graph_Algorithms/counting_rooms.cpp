// CSES Graph Problem 1
#include <iostream>
#include <vector>
#define P pair<int, int>
using namespace std;

// URDL
vector<P> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void dfs(vector<vector<char>> &matrix, int x, int y, int n, int m)
{
    if (x < 0 || y < 0 || x >= n || y >= m || matrix[x][y] == '#')
        return;
    matrix[x][y] = '#';
    for (int i = 0; i < 4; i++)
    {
        int row = dir[i].first + x;
        int col = dir[i].second + y;
        dfs(matrix, row, col, n, m);
    }
}
int solve(vector<vector<char>> &matrix, int n, int m)
{
    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '.')
            {
                dfs(matrix, i, j, n, m);
                rooms++;
            }
        }
    }
    return rooms;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    cout << solve(matrix, n, m) << endl;
}