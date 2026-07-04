#include <iostream>
#include <vector>
using namespace std;

int n,k;                                           //从n个数字中选择k个作为一种组合
vector<int> chosen;                                //存储当前选择的组合

void dfs(int start){                               //从start开始选择数字
    // 1. 退出递归的条件：已经选了 k 个元素
    if(chosen.size()==k){
        for(int i=0;i<k;i++){
            cout<<chosen[i]<<" ";
        }

        cout<<endl;

        return;
    }

    // 2. 剪枝优化（可选但推荐）：
    // 如果剩下的元素数量不足以凑齐 k 个，直接返回
    // 还需要选 k - chosen.size() 个，剩余可选范围是 [start, n]，共 n - start + 1 个
    if(n-start+1<k-chosen.size()){
        return;
    }

    // 3. 从 start 开始遍历，枚举当前位置可以选哪个数
    for(int i=start;i<=n;i++){
        chosen.push_back(i);                   // 选第 i 个元素
        dfs(i+1);                            // 递归进入下一层，下一个元素只能从 i+1 开始选（保证不重复）
        chosen.pop_back();                         // 回溯：撤销刚才的选择，尝试下一个元素
    }

}

int main(){
    cin>>n>>k;

    //从1开始枚举
    dfs(1);

    return 0;
}