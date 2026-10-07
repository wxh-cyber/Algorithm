#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * 先序遍历：访问根节点，递归访问左子树，递归访问右子树
 * @param root 根节点
 * @param res 结果
 */
void preOrder(TreeNode *root, vector<int> &res) {
  if (root == nullptr) {
    return;
  }

  res.push_back(root->val);   // 访问根节点
  preOrder(root->left, res);  // 递归访问左子树
  preOrder(root->right, res); // 递归访问右子树
}

int main() {
    /* 构造如下二叉树:
            1
           / \
          2   3
         / \
        4   5
    */
  TreeNode *root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(3);
  root -> left->left = new TreeNode(4);
  root -> left->right = new TreeNode(5);

  vector<int> res;
  preOrder(root, res);

  for (int x :res) {
    cout << x << " ";
  }

  return 0;
}