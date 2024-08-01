/**
 * https://leetcode.cn/problems/jump-game-ii/description/
 */

#include <vector>
using std::vector;

class Solution {
public:
  int jump(vector<int> &nums) {
    vector<int> steps(nums.size(), -1);

    steps[0] = 0;
    for (int i = 1; i < nums.size(); i++) {
      int min_steps = -1;

      for (int j = 0; j < i; j++) {
        if (nums[j] + j >= i && steps[j] != -1)
          min_steps = (min_steps == -1 || steps[j] + 1 < min_steps)
                          ? steps[j] + 1
                          : min_steps;
      }

      steps[i] = min_steps;
    }

    return steps.back();
  }
};

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  vector<int> nums = {2, 3, 1, 1, 4};

  Solution s;
  cout << s.jump(nums) << endl;

  return 0;
}
