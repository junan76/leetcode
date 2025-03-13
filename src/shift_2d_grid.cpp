#include <vector>
using std::vector;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        k = k % (m * n);

        if (k > m * n / 2)
        {
            k = m * n - k;
            while (k--)
                shiftLeft(grid);
        }
        else
        {
            while (k--)
                shiftRight(grid);
        }

        return grid;
    }

private:
    void shiftLeft(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int first = grid[0][0];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == m - 1 && j == n - 1)
                    grid[i][j] = first;
                else if (j == n - 1)
                    grid[i][j] = grid[i + 1][0];
                else
                    grid[i][j] = grid[i][j + 1];
            }
        }
    }

    void shiftRight(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int last = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == 0 && j == 0)
                    grid[i][j] = last;
                else if (j == 0)
                    grid[i][j] = grid[i - 1][n - 1];
                else
                    grid[i][j] = grid[i][j - 1];
            }
        }
    }
};