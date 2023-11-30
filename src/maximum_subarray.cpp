#include <vector>
using namespace std;

/**
 * 和最大的子数组.
 *
 * NOTE: 动态规划. 定义f(n)是an为结尾, 子数组的最大和. 那么:
 * f(n) = an;              if f(n-1) < 0
 *      = f(n-1) + an;     otherwise
 */
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int result = nums[0];

    int* table = new int[nums.size()]{0};
    table[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      if (table[i - 1] >= 0) {
        table[i] = table[i - 1] + nums[i];
      } else {
        table[i] = nums[i];
      }
      result = max(result, table[i]);
    }

    return result;
  }
};