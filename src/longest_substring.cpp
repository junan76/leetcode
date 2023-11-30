#include <string>
#include <set>

using namespace std;

/**
 * 暴力求解, 三层循环.
 */
class Solution1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;

        int start = 0;
        int end = 1;
        bool repeated = false;

        // 枚举起点
        for (start = 0; start < s.length(); start++)
        {
            // 枚举终点
            for (end = start + 1; end < s.length(); end++)
            {
                // 检查终点是否和之前的字符重复
                for (int i = start; i < end; i++)
                {
                    if (s[i] == s[end])
                    {
                        repeated = true;
                        break;
                    }
                }

                if (repeated)
                {
                    break;
                }
            }
            result = max(result, end - start);

            repeated = false;
            if (end >= s.length())
            {
                break;
            }
        }

        return result;
    }
};