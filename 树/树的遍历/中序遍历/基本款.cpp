#include <iostream>
#include <vector>
using namespace std;

/**
 *  @brief TreeNode - 树的节点
 *  @param {int} val - 树的根节点的值
 *  @param {TreeNode} left - 树的左子树节点
 *  @param {TreeNode} right - 树的右子树节点
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 *  @brief inOrder - 中序遍历
 *  @param {TreeNode} root - 根节点
 *  @param {vector<int>} res - 中序遍历结果
 */
void inOrder(TreeNode *root, vector<int> &res) {
  if (root == nullptr)
    return;

  inOrder(root->left, res);  // 递归左子树
  res.push_back(root->val);  // 访问根节点
  inOrder(root->right, res); // 递归右子树
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
  
  inOrder(root, res); 
  for (int x : res)
    cout << x << " ";

  return 0;
}