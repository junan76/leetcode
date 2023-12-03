class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 2) return n;

    int result = 0;
    int dn_1 = 2;
    int dn_2 = 1;

    for (int i = 3; i <= n; i++) {
      result = dn_1 + dn_2;
      dn_2 = dn_1;
      dn_1 = result;
    }

    return result;
  }
};