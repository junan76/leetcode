#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> result;
        int m = mat.size();
        int n = mat[0].size();

        int x = 0, y = 0;
        int x_step = 1, y_step = -1;
        bool dir_change = false;

        while (result.size() < m * n)
        {
            result.push_back(mat[y][x]);
            x += x_step;
            y += y_step;

            if (y >= m)
            {
                y -= 1;
                x += 2;
                dir_change = true;
            }
            else if (x >= n)
            {
                x -= 1;
                y += 2;
                dir_change = true;
            }
            else if (x < 0)
            {
                x += 1;
                dir_change = true;
            }
            else if (y < 0)
            {
                y += 1;
                dir_change = true;
            }

            if (dir_change)
            {
                x_step = -x_step;
                y_step = -y_step;
                dir_change = false;
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat = {{2, 3, 4}, {5, 6, 7}};
    Solution s;
    vector<int> result = s.findDiagonalOrder(mat);
    std::for_each(result.begin(), result.end(), [](int x)
                  { std::cout << x << " "; });

    return 0;
}
