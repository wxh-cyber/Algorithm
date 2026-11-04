/**
 *  @link https://www.luogu.com.cn/problem/P1873
 */

 #include <iostream>
 using namespace std;
 typedef long long ll;

 const int MAXN=1e6+5;

 int n;                                                   //n表示树的总数
 ll m,leftx,rightx,mid;                                   //m表示木材总长度，leftx和rightx分别表示高度的左右边界，mid表示二分时取中的结果
 int nums[MAXN];                                          //nums表示所有输入的树的高度

 /** 
  *  @brief check - 检查高度是否符合要求
  *  @param {int} x - 高度
  *  @return {true|false} - 是否符合要求
  */
 bool check(int x){
    ll s=0;                                               //由于m的范围为ll，故s作为统计木材总长度，也设定为ll

    for(int i=1;i<=n;i++){
        if(nums[i]>x){
            s+=(nums[i]-x);                               //依次遍历nums中的各数，如果nums[i]>x，则总长度也相应增加
        }

        if(s>=m) return true;                             //符合要求，返回true
    }

    return false;                                         //不符合要求，返回false
 }

 int main(){
    cin>>n>>m;                                            //输入树的数量和木材长度

    for(int i=1;i<=n;i++){
        cin>>nums[i];                                     //输入所有树的高度
    }

    leftx=0;                                              //定义高度左右区间
    rightx=1e9;
    while(leftx<=rightx){ 
        mid=leftx+(rightx-leftx)/2;                       //每次都取区间中部标记为mid
        if(check(mid)){
            leftx=mid+1;                                  //如果符合要求，说明高度还可以再升高，因此改变左侧区间
        }else{
            rightx=mid-1;                                 //否则，更改右侧区间
        }
    }

    cout<<rightx<<endl;                                   //由于输出尽可能高的高度，故最终输出右侧区间

    return 0;
 }