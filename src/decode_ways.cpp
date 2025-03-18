#include <string>
using std::string;

/**
 *
 * 递归求解, Timeout.
 */
class Solution1
{
public:
    int numDecodings(string s)
    {
        return numDecodings(s, 0, s.length() - 1);
    }

private:
    int numDecodings(string s, int start, int end)
    {
        if (start > end)
            return 1;
        if (start == end)
            return s[start] == '0' ? 0 : 1;

        int result = 0;
        if (s[start] == '0')
            return 0;

        result += numDecodings(s, start + 1, end);
        if (start + 1 <= end)
        {
            if ((s[start] - '0') * 10 + s[start + 1] - '0' <= 26)
                result += numDecodings(s, start + 2, end);
        }

        return result;
    }
};

#include <vector>
using std::vector;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> dp(n, 0);

        if (s[0] != '0')
            dp[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (s[i] != '0')
                dp[i] += dp[i - 1];

            if (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
                dp[i] += (i >= 2 ? dp[i - 2] : 1);
        }

        return dp[n - 1];
    }
};
