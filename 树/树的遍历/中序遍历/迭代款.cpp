#include <iostream>
#include <stack>
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
 *  @param {TreeNode} root - 树的根节点
 *  @return res - 中序遍历序列
 */
vector<int> inOrder(TreeNode *root) {
  vector<int> res;
  stack<TreeNode *> st;
  TreeNode *cur = root;

  while (cur || !st.empty()) {
    while (cur) { // 一路向左，沿途节点入栈
      st.push(cur);
      cur = cur->left;
    }
    cur = st.top();
    st.pop();
    res.push_back(cur->val); // 访问节点
    cur = cur->right;        // 转向右子树
  }
  return res;
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
  inOrder(root);
  for (int x : res) 
    cout << x << " ";

  return 0;
}