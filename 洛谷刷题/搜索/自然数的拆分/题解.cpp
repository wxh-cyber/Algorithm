/**
 *  @link https://www.luogu.com.cn/problem/P2404
 */

 #include <iostream>
 using namespace std;

 const int MAXN=10;

 int n;                                                //n表示要拆分的自然数
 int a[MAXN]={1};                                  //a[MAXN]表示单次拆分的数组

 void print(int);

 /**
  *  @brief search - 深度搜索函数
  *  @param {int} s - 当前剩余的待拆分的数
  *  @param {int} t - 当前即将填充的数组下标
  *  @return 无
  */
 void search(int s,int t){
    /**
     *  @note
     *    由于i从小到大递增，因此可以保证a数组中的数一定是单调不减的
     *    通过设定i的下限为原数组中最后一个最大的数，上限为s，可以保证s-i≥0
     */
    for(int i=a[t-1];i<=s;i++){                                   
        if(i<n){                                                  //在外层添加if是为了保证不会出现单独的一个n这种特殊情况
            a[t]=i;                                               //将i放置到数组中的最后一位
            s-=i;                                                 //从s中拆分出一个i
            if(s==0) {
                print(t);                                         //如果此时s为0，则输出结果
            }else{
                search(s,t+1);                                 //否则继续深度搜索
            }

            s+=i;                                                //回溯
        }
    }
 }

 /**
  *  @brief print - 输出单个拆分结果
  *  @param {int} t - 数组右侧下标
  *  @return 无
  */
 void print(int t){
    for(int i=1;i<t;i++){
        cout<<a[i]<<"+";
    }
    cout<<a[t]<<endl;
 }

 int main(){
    cin>>n;                                            //输入待拆分的数n
    search(n,1);                                  //注意由于初始时用到a[0]，所以初始下标从1开始

    return 0;
 }