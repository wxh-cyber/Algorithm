#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 *  @brief preOrder - 先序遍历
 *  @param {TreeNode} root - 树的根节点
 *  @return res - 先序遍历序列
 */
vector<int> preOrder(TreeNode *root) {
  vector<int> res;

  if (!root)
    return res;

  stack<TreeNode *> st;
  st.push(root);
  while (!st.empty()) {
    TreeNode *node = st.top();
    st.pop();
    res.push_back(node->val);

    // 先压右孩子，后压左孩子（栈是后进先出）
    if (node->right) {
      st.push(node->right);
    }
    if (node->left) {
      st.push(node->left);
    }
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
  preOrder(root);
  for(int x:res){
    cout<<x<<" ";
  }

  return 0;
}