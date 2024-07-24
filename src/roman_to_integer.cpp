/**
 * https://leetcode.cn/problems/roman-to-integer/description/
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  int romanToInt(string s) {

    int result = 0;
    int value = 0, next_value = 0;
    int i = s.length();

    while (i > 0) {
      result += value;
      if (value < 0)
        value = -value;

      i -= 1;
      next_value = symbol_value(s[i]);

      if (next_value < value)
        value = -next_value;
      else
        value = next_value;
    }
    result += value;

    return result;
  }

private:
  int symbol_value(char symbol) {

    int values[] = {1, 5, 10, 50, 100, 500, 1000};
    char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    for (int i = 0; i < 7; i++) {
      if (symbol == symbols[i])
        return values[i];
    }

    return 0;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  cout << s.romanToInt("III") << endl;
  cout << s.romanToInt("LVIII") << endl;
  cout << s.romanToInt("MCMXCIV") << endl;

  return 0;
}
