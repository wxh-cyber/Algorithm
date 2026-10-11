#include <iostream>
#include <vector>
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
    stack<TreeNode*> st;
    TreeNode* cur=root,*prev=nullptr;
    while(cur||!st.empty()){
        while(cur){                                //一路向左（与中序类似）
            st.push(cur);
            cur=cur->left;
        }
        cur=st.top();                              //窥视栈顶，但是不弹出
        if (!cur->right || cur->right == prev) {
            res.push_back(cur->val);          // 右子树已访问完，才能访问根
            st.pop();
            prev = cur;                           //更新最近完成的回执
            cur = nullptr;                        //节点退役，防止重复处理
        } 
        else{
            cur = cur->right;                     //右子树未开工->转向右子树
        }
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

    res=postOrder(root);
    for (int x : res) 
        cout << x << " ";

    return 0;
}