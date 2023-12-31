#include <set>
#include <string>

using namespace std;

/**
 * 暴力求解, 三层循环.
 */
class Solution1 {
 public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;

    int start = 0;
    int end = 1;
    bool repeated = false;

    // 枚举起点
    for (start = 0; start < s.length(); start++) {
      // 枚举终点
      for (end = start + 1; end < s.length(); end++) {
        // 检查终点是否和之前的字符重复
        for (int i = start; i < end; i++) {
          if (s[i] == s[end]) {
            repeated = true;
            break;
          }
        }

        if (repeated) {
          break;
        }
      }
      result = max(result, end - start);

      repeated = false;
      if (end >= s.length()) {
        break;
      }
    }

    return result;
  }
};

/**
 * 使用滑动窗口的方式.
 *
 * NOTE: [start, end)是无重复子串的范围, 循环之中会计算全部无重复子串的长度,
 * 并保存最长的.
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;

    int start = 0;
    int end = 1;
    set<char> sub;
    if (s.length() > 0) sub.insert(s[0]);

    while (start < s.length() && end <= s.length()) {
      result = max(result, end - start);
      if (sub.count(s[end]) != 0) {
        sub.erase(s[start]);
        start++;
        if (start == end && start < s.length()) {
          sub.insert(s[start]);
          end = start + 1;
        }
      } else {
        sub.insert(s[end]);
        end++;
      }
    }

    return result;
  }
};