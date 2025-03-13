#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
class Solution
{
public:
    /**
     * @param x: the integer to be reversed
     * @return: the reversed integer
     * 
     * 题目要求, 限制了输入的数字范围, 并且一旦超出范围, 立即返回0即可.
     */
    int reverse(int x)
    {
        int result = 0;
        while (x != 0)
        {
            if (result > INT_MAX / 10)
                return 0;
            if (result < INT_MIN / 10 && x < 0)
                return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int x = atoi(argv[1]);
    int result = s.reverse(x);
    cout << result << endl;
    return 0;
}