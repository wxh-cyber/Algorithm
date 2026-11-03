/**
 *  @link https://www.luogu.com.cn/problem/P1102
 */

 #include <iostream>
 #include <algorithm>
 using namespace std;
 typedef long long ll;

 const int MAXN=2e5+5;

 int n;                                                       //n表示数的总数
 ll c;                                                        //c表示差值
 ll nums[MAXN];                                               //nums数组存放所有输入的数
 ll ans=0;                                                    //ans表示最终结果

 int main(){
    cin>>n>>c;                                                //输入数的总数和差值

    for(int i=1;i<=n;i++){
        cin>>nums[i];                                         //输入所有的数
    }

    sort(nums+1,nums+n+1);                        //按照从小到大进行排序

    /**
     *  @note
     *    题目要求A-B=C，事实上，可以看成A=B+C，那么对于每一个加数来说，只需要找出加上C后的和的数量，即为所求结果
     */
    for(int i=1;i<=n;i++){
        ans+=((upper_bound(nums+1,nums+n+1,nums[i]+c)-lower_bound(nums+1,nums+n+1,nums[i]+c)));
    }

    cout<<ans;

    return 0;
 }