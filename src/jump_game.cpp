#include <vector>
using namespace std;

/**
 * 方法1: 勉强通过.
 *
 * NOTE: 时间和空间复杂度都太高.
 */
class Solution1 {
 public:
  bool canJump(vector<int>& nums) {
    vector<bool> can_jump(nums.size(), false);
    can_jump[0] = true;

    for (int pos = 0; pos < nums.size(); pos++) {
      updateCanJump(nums, pos, can_jump);
      if (can_jump.back()) break;
    }

    return can_jump.back();
  }

 private:
  void updateCanJump(const vector<int>& nums, int position,
                     vector<bool>& can_jump) {
    if (can_jump[position] == false) return;

    int steps = nums[position];
    for (int i = 1; i <= steps && position + i < nums.size(); i++) {
      can_jump[position + i] = true;
    }
  }
};

/**
 * 方法2: 贪心, 依次遍历, 记录能到达的最远的位置.
 */
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int N = nums.size() - 1;
    int farest = 0;

    for (int i = 0; i <= N; i++) {
      if (farest >= N) break;
      if (i <= farest) {
        farest = max(farest, i + nums[i]);
      } else
        break;
    }

    return farest >= N;
  }
};