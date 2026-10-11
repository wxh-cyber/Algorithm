#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> res;
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
 *  @brief postOrder - 后序遍历
 *  @param {TreeNode} root - 树的根节点
 *  @return {vector<int>} res - 后序遍历序列
 */
vector<int> postOrder(TreeNode* root){
    vector<int> res;
    if(!root) return res;

    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();
        res.push_back(node->val);
         
        // 先压左孩子，再压右孩子（得到 根右左）
        if (node->left)  st.push(node->left);
        if (node->right) st.push(node->right);
    }

    reverse(res.begin(), res.end());  // 反转 → 左右根
    return res;
}

int main(){
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

    res=postOrder(root);
    for (int x : res) 
        cout << x << " ";

    return 0;
}