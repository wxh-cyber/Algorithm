#include <iostream>
#include <vector>
#include <queue>
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
 *  @brief levelOrder - 层次遍历
 *  @param {TreeNode} root - 树的根节点
 *  @return {vector<int>} res - 层次遍历序列
 */
vector<int> levelOrder(TreeNode* root){
    vector<int> res;
    if(!root) return res;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();                    //取队首（注意：q.pop()不返回值）
        q.pop();
        res.push_back(node->val);

        if(node->left) q.push(node->left);      //孩子追加到队尾
        if(node->right) q.push(node->right);
    }

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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    res=levelOrder(root);
    for (int x : res) 
        cout << x << " ";

    return 0;
}