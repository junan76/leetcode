#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/**
 * 暴力求解, 两层循环遍历.
 */
class Solution1 {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result = {};

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          result.push_back(i);
          result.push_back(j);
          break;
        }
      }
    }

    return result;
  }
};

/**
 * 使用multimap, 先对元素进行排序, 然后再进行一次O(n)的遍历即可.
 * NOTE: 向map中插入元素就相当于排序了, 因为map是有序数据结构.
 */
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result = {};
    multimap<int, int> nums_sorted;
    int index = 0;

    for_each(nums.begin(), nums.end(), [&](int n) {
      nums_sorted.insert({n, index++});
    });

    auto i = nums_sorted.begin();
    auto j = nums_sorted.end();
    j--;

    while (i != j) {
      int sum = i->first + j->first;
      if (sum == target) {
        result.push_back(i->second);
        result.push_back(j->second);
        break;
      } else if (sum < target) {
        i++;
      } else {
        j--;
      }
    }

    return result;
  }
};