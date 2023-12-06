#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) return strs[0];

    string result;
    int index = 0;
    char c = -1;
    bool loop = true;

    while (loop) {
      for (auto s : strs) {
        if (index >= s.size()) {
          loop = false;
          break;
        }
        if (c == -1) c = s[index];
        if (c != s[index]) {
          loop = false;
          break;
        }
      }
      if (c != -1 && loop) result += c;
      index++;
      c = -1;
    }

    return result;
  }
};