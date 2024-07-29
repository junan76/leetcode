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
class Solution1 {
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

/**
 * 排序之后使用双指针, 复杂度降为O(n^2)
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> results;
    vector<int> answer;
    std::sort(nums.begin(), nums.end());

    int i = 0, j, k;
    int n = nums.size();

    for (; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      answer.push_back(nums[i]);
      j = i + 1;
      k = n - 1;

      while (j < k) {
        if (nums[j] + nums[k] > -nums[i])
          k--;
        else if ((nums[j] + nums[k] < -nums[i]))
          j++;
        else {
          answer.push_back(nums[j]);
          answer.push_back(nums[k]);
          results.push_back(vector<int>(answer));
          answer.pop_back();
          answer.pop_back();
          j++;
          k--;

          while (j < k && nums[j] == nums[j - 1])
            j++;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        }
      }

      answer.pop_back();
    }

    return results;
  }
};

/**
 * qwen2优化之后的结果. 原始代码在跳过重复元素部分有错, 需要修改.
 */
class Solution_qwen2 {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> results;

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int j = i + 1, k = nums.size() - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum > 0)
          --k;
        else if (sum < 0)
          ++j;
        else {
          /*满足条件的结果, 一次性push_back*/
          results.push_back({nums[i], nums[j], nums[k]});

          /*跳过重复元素*/
          do {
            ++j;
          } while (j < k && nums[j] == nums[j - 1]);
          do {
            --k;
          } while (k > j && nums[k] == nums[k + 1]);
        }
      }
    }

    return results;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums = {-3, -2, -2, -1, 4, 5, 5};
  Solution_qwen2 s;

  auto results = s.threeSum(nums);
  std::for_each(results.begin(), results.end(), [](vector<int> answer) {
    if (answer.empty())
      return;
    cout << answer[0] << ", " << answer[1] << ", " << answer[2] << endl;
  });

  return 0;
}
