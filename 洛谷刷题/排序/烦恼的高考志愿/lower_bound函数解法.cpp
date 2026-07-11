/**
 *  @link https://www.luogu.com.cn/problem/P1678
 */

#include <iostream>
#include <climits>
#include <algorithm>
typedef long long ll;
using namespace std;

/**
 *  climits:  LLONG_MAX LLONG_MIN INT_MAX INT_MIN
 *  algorithm:sort、lower_bound
 */

const int MAXM=1e5+5;                                   //设定学校最大数量
const int MAXN=1e5+5;                                   //设定学生最大数量

int m,n;                                                //学校数量、学生数量
ll schools[MAXM]={0},students[MAXN]={0};        //存放学校分数线和学生分数
ll ans=0;                                               //存放答案

int main(){
    cin>>m>>n;                                          //输入学校数量、学生数量
    for(int i=0;i<m;i++){
        cin>>schools[i];
    }

    for(int i=0;i<n;i++){
        cin>>students[i];
    }

    //给学校分数排序
    sort(schools,schools+m);

    for(int i=0;i<n;i++){
        //使用lower_bound函数查找第一个大于等于该学生分数的学校的下标
        //通过二分查找保证查找时间复杂度为O(logn)
        int pos=lower_bound(schools,schools+m,students[i])-schools;

        ll tmp=LLONG_MAX;
        if(pos<m) tmp=min(tmp,llabs(schools[pos]-students[i]));
        if(pos>0) tmp=min(tmp,llabs(schools[pos-1]-students[i])); 
        
        ans+=tmp;
    }

    cout<<ans;
    
    return 0;
}