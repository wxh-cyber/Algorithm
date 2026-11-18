/**
 *  @link https://www.luogu.com.cn/problem/P1353
 */

 #include <iostream>
 #include <algorithm>
 using namespace std;

 const int MAXN=1e4+500;                                  //时间上限，至少应当开辟到1e4+500，保证数组不越界
 const int MAXM=505;                                      //疲劳度上限

 int n,m;                                                 //总时长、疲劳度              
 int d[MAXN];                                             //每分钟距离
 int f[MAXN][MAXM];                                       //f[i][j]表示第i分钟时，疲劳度为j时，可以走的最大距离

 int main(){
    cin>>n>>m;                                            //输入总时长和疲劳度
    for(int i=1;i<=n;i++){
        cin>>d[i];                                        //输入每分钟距离
    }

    f[1][1]=d[1];                                         //显然边界状态为：f[1][0]=0,f[1][1]=d[1]
    for(int i=1;i<n;i++){                                 //为了保证最后疲劳度为0，显然最后一分钟只能休息
        /**
         *  @note
         *    j的遍历：
         *      - j为0表示时刻为i时休息
         *      - 显然，当i<m时，不可能累计到m的疲劳度，最大只能为i，而当i>=m时，疲劳度上限为m
         */
        for(int j=0;j<=min(i,m);j++){
            //由于任意i分钟，都有保持休息和继续行动两种行为，因此需要对两种不同的行为进行更新
            if(j==0)                                               
                //第i分钟疲劳度已经为0，还继续保持休息状态
                f[i+1][0]=max(f[i+1][0],f[i][0]);
            else if(i+j<=n)                      //增加边界条件，保证不会越界
                //第i分钟疲劳度为j，选择休息，则一直到第i+j分钟，距离都保持不变
                f[i+j][0]=max(f[i+j][0],f[i][j]);

            //第i分钟继续行动
            if(j<m)
                f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+d[i+1]);
        }
    }

    cout<<f[n][0]<<endl;                         //输出最终答案

    return 0;
 }