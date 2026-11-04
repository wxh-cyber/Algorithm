/**
 *  @link https://www.luogu.com.cn/problem/P1873
 */

 #include <cstdio>
 #include <algorithm>
 using namespace std;
 typedef long long ll;

 const int MAXN=1e6+5;

 int n,num,ans;                                                   //n表示树的总数，num是指针下标，ans返回最终结果
 ll m,sum;                                                        //m是要求的木材总长度，sum用于存储过程中的木材总长度
 int tree[MAXN];                                                  //采用tree数组存储所有树的高度

 int main(){
    scanf("%d%lld",&n,&m);                                //输入树的总数和要求的木材长度
    for(int i=1;i<=n;i++){
        scanf("%d",&tree[i]);                             //输入所有树的高度
    }

    sort(tree+1,tree+n+1);                           //将树的高度从低到高进行排序

    num=n;                                                       //初始状态下，指针从最末尾的n开始，从后往前遍历
    while(sum<m){                                                //如果当前木材总长度小于规定的长度，则一直执行循环
        sum+=(tree[num]-tree[num-1])*(n-num+1);                  //每次增加的结果为（当前树的高度-后一棵树的高度）×从后往前的序号
        num--;                                                   //将num指针前移
    }
    num++;                                                       //特别地，当跳出循环时，num实际上指向了符合规定下标的前面一个下标，因此num自增一次，则恰好指向符合规定的下标
    ans=tree[num-1]+(sum-m)/(n-num+1);                           //将多出来的高度sum-m均摊到所有被截断的树木上，则可以得到最大高度ans

    printf("%d",ans);                                    //输出最终结果

    return 0;
 }