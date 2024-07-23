/**
 * https://leetcode.cn/problems/integer-to-roman/description/
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  string intToRoman(int num) {
    string symbols[] = {"I",  "IV", "V",  "IX", "X",  "XL", "L",
                        "XC", "C",  "CD", "D",  "CM", "M",  ""};
    int values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000, 4000};
    string roman = "";
    int i = 12;

    while (num) {
      if (num >= values[i] && num < values[i + 1]) {
        num -= values[i];
        roman += symbols[i];
        continue;
      }
      i -= 1;
    }

    return roman;
  }
};

int main(int argc, char const *argv[]) {
  int num = 3999;
  if (argc > 1)
    num = atoi(argv[1]);

  Solution s;
  cout << num << ": " << s.intToRoman(num) << endl;

  return 0;
}
