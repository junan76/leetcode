#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  string intToRoman(int num) {
    string roman = "";

    roman += to_roman3(num / 1000 * 1000);
    roman += to_roman2(num % 1000 / 100 * 100);
    roman += to_roman1(num % 100 / 10 * 10);
    roman += to_roman0(num % 10);

    return roman;
  }

private:
  string to_roman0(int num) {
    if (!(num >= 1 && num <= 9))
      return "";
    else if (num == 4)
      return "IV";
    else if (num == 9)
      return "IX";

    string result = "";
    if (num >= 5) {
      result += "V";
      num -= 5;
    }

    while (num > 0) {
      result += "I";
      num -= 1;
    }

    return result;
  }

  string to_roman1(int num) {
    if (!(num >= 10 && num <= 90))
      return "";
    else if (num == 40)
      return "XL";
    else if (num == 90)
      return "XC";

    string result = "";
    if (num >= 50) {
      result += "L";
      num -= 50;
    }

    while (num > 0) {
      result += "X";
      num -= 10;
    }

    return result;
  }

  string to_roman2(int num) {
    if (!(num >= 100 && num <= 900))
      return "";
    else if (num == 400)
      return "CD";
    else if (num == 900)
      return "CM";

    string result = "";
    if (num >= 500) {
      result += "D";
      num -= 500;
    }

    while (num > 0) {
      result += "C";
      num -= 100;
    }

    return result;
  }

  string to_roman3(int num) {
    if (!(num >= 1000 && num <= 3000))
      return "";

    string result = "";

    while (num > 0) {
      result += "M";
      num -= 1000;
    }

    return result;
  }
};

int main(int argc, char const *argv[])
{
    int num = 3999;
    if (argc > 1)
        num = atoi(argv[1]);
    
    Solution s;
    cout << num << ": " << s.intToRoman(num) << endl;;

    return 0;
}
