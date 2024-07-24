/**
 * https://leetcode.cn/problems/3sum/
 */

#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

/**
 * 三重循环, 暴力求解.
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> results;
    vector<int> answer;

    std::sort(nums.begin(), nums.end());
    int i, j, k;
    int n = nums.size();
    int sum = 0;

    for (i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      if (sum >= 0 && nums[i] > 0)
        break;
      sum += nums[i];
      answer.push_back(nums[i]);

      for (j = i + 1; j < n; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        if (sum >= 0 && nums[j] > 0)
          break;
        sum += nums[j];
        answer.push_back(nums[j]);

        for (k = j + 1; k < n; k++) {
          if (k > j + 1 && nums[k] == nums[k - 1])
            continue;
          if (sum >= 0 && nums[k] > 0)
            break;
          sum += nums[k];
          answer.push_back(nums[k]);

          if (sum == 0)
            results.push_back(vector<int>(answer));

          answer.pop_back();
          sum -= nums[k];
        }

        answer.pop_back();
        sum -= nums[j];
      }

      answer.pop_back();
      sum -= nums[i];
    }

    return results;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums = {-1, 0, 0, 1, 2, -1, -4};
  Solution s;

  auto results = s.threeSum(nums);
  std::for_each(results.begin(), results.end(), [](vector<int> answer) {
    if (answer.empty())
      return;
    cout << answer[0] << ", " << answer[1] << ", " << answer[2] << endl;
  });

  return 0;
}
