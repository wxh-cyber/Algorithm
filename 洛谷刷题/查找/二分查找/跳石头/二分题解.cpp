/**
 *  @link https://www.luogu.com.cn/problem/P2678
 */

 #include <iostream>
 #include <cstdio>
 #include <cctype>
 using namespace std;
 typedef long long ll;

 const int MAXN=5e5+5;

 int n,m;                                                    //n表示石头总数，m表示需要移除的数量
 ll l,leftx,rightx,mid,ans;                                  //l表示从起点到终点的总距离，leftx、rightx和mid分别表示区间的左侧、右侧和中间，ans表示最终结果
 ll dist[MAXN];                                              //dis[i]表示第i个石头到起点的距离

 /**
  *  @brief read - 快速读
  *  @return 无
  */
 inline int read(){
    int x=0;                                                 //x是累计值
    bool f=1;                                                //f判断正负，1为正，-1为负
    char ch=getchar();                                       //输入字符

    //若字符不是数字且该字符不能输出，则直接跳过
    while(!isdigit(ch)&&!isgraph(ch)){
        ch=getchar();
    }

    //若该字符为负号，则更改f为-1，并继续输入其他字符
    if(ch=='-'){
        f=-1;
        ch=getchar();
    }

    //若该字符为数字，则将字符类型转换为int后，累加到x上
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^'0');
        ch=getchar();
    }

    return x*f;                                       //返回最终结果
 }

 /**
  *  @brief judge - 判断x是否为符合条件的值
  *  @param {int} x - 距离
  *  @return {true|false} - 是否符合条件
  *  @note 时间复杂度O(n)
  *  @note
  *    注意：在移动石头时，贪心算法选择的是“保左去右”。
  *         因为保留左边的 now 当落脚点，后面每块石头到它的距离都比到 i 更远，后面更容易满足 ≥ x。
  *         反过来保留右边那块，反而把后续石头“拉近”了，更难达标。
  *  @note 
  *    终点 dist[n+1] 其实不能被移走，但代码在 dist[n+1] - dist[now] < x 时也会 tot++，这不影响正确性：
  *    - 若此时 now 是某块真实石头：这个 ++ 可以理解为“改为移走 now 这块保留石”。
  *      移走后，更前面那块保留石到终点的距离 = 两段之和 ≥ x（因为 now 当初保留时与前一块的间距已 ≥ x），仍然合法，且移除总数不变；
  *    - 若 now 还是起点 0：说明 n 块石头全被移光、起点到终点仍 < x，此时 tot =  n ≥ m，必然返回 false——这也是对的，因为连全部移光，最短一跳都只有 l < x。
  */
 bool judge(int x){
    int tot=0;                                       //tot是当前已经移除的石头数
    int i=0;                                         //i从1到n依次遍历每块石头
    int now=0;                                       //now代表每次比较时，上一块未被移除的石头
    while(i<n+1){                                    //依次遍历每块石头
        i++;
        if(dist[i]-dist[now]<x){                     //若两者间的距离小于x，则需要移走第i块石头
            tot++;
        }else{
            now=i;                                   //否则不移走任何石头，更新now为i
        }
    }

    if(tot>m){
        return false;                               //如果最后为了保证每块石头彼此之间的距离大于x，移动的数量已经超过了m，则不符合条件，返回false
    }else{
        return true;                                //否则返回true
    }
 }

 int main(){
    l=read();                                        //输入起点和终点距离l
    n=read();                                        //石头总数
    m=read();                                        //要求移除的数量

    for(int i=1;i<=n;i++){
        dist[i]=read();                              //输入每块石头到起点的距离
    }
    dist[n+1]=l;                                     //第n+1块石头，实际上就是终点

    leftx=1,rightx=l;                                //初始化左右区间
    while(leftx<=rightx){
        mid=leftx+(rightx-leftx)/2;
        if(judge(mid)){                           //若中间的数符合条件，则更新ans
            ans=mid;
            leftx=mid+1;                            //同时表明可能存在更大的数，故更改左侧leftx
        }else{
            rightx=mid-1;                           //否则更改右侧rightx
        }
    }

    cout<<ans<<endl;                                //输出最终结果

    return 0;
 }