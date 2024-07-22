#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**
 * 暴力求解法.
 */
class Solution1
{
public:
  string
  longestPalindrome (string s)
  {
    string result = "";
    if (s.empty () || s.length () == 1)
      return s;

    int n = s.length ();
    for (int i = 0; i < n; i++)
      {
        for (int j = n - 1; j >= i; j--)
          {
            if (is_palindrome (s, i, j))
              {
                string ps = s.substr (i, j - i + 1);
                if (result.length () < ps.length ())
                  result = ps;
              }
          }
      }

    return result;
  }

  bool
  is_palindrome (string s, int start, int end)
  {
    int i = start, j = end;
    while (i <= j)
      {
        if (s[i] != s[j])
          return false;
        i++;
        j--;
      }

    return true;
  }
};

/**
 * 动态规划算法.
 */
class Solution
{
public:
  string
  longestPalindrome (string s)
  {
    string result = "";
    int n = s.length ();
    bool dp[n][n];

    for (int index = 0; index < n; index++)
      {
        for (int i = 0; i < n - index; i++)
          {
            int j = i + index;

            if (i == j)
              dp[i][j] = true;
            else if (j == i + 1)
              dp[i][j] = (s[i] == s[j]);
            else
              dp[i][j] = (dp[i + 1][j - 1] && (s[i] == s[j]));

            if (dp[i][j] && result.length () < j - i + 1)
              result = s.substr (i, j - i + 1);
          }
      }

    return result;
  }
};

int
main (int argc, char const *argv[])
{
  Solution s;

  cout << s.longestPalindrome ("babad") << endl;
  cout << s.longestPalindrome ("cbbd") << endl;

  return 0;
}
