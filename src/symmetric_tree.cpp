#include "leetcode.h"

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;

    return compareTrees(root->left, root->right);
  }

 private:
  bool compareTrees(const TreeNode *left, const TreeNode *right) {
    if (left == right && left == nullptr) return true;

    if ((left != nullptr && right == nullptr) ||
        (left == nullptr && right != nullptr) || left->val != right->val)
      return false;

    return compareTrees(left->left, right->right) &&
           compareTrees(left->right, right->left);
  }
};