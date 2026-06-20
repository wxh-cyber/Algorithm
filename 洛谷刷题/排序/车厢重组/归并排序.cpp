/**
 *  @link https://www.luogu.com.cn/problem/P1116
 */

 #include <iostream>
 using namespace std;

 const int MAXN=1e5+5;

 int n,arr[MAXN];
 int tmp[MAXN],ans=0;

 void mySort(int arr[],int left,int right){
    //如果数组中只有一个元素或者没有元素，那么就直接返回
    if(right-left==1||right-left==0) {
        return;
    }

    int mid=left+((right-left)>>1);                         //mid为数组的中间位置
    int p1=left,p2=mid;                                     //p1表示双指针左区间最小值，p2表示双指针右区间最小值
    int len=0;                                              //len表示子串长度

    mySort(arr,left,mid);                            //左区间
    mySort(arr,mid,right);                            //右区间 

    while(p1<mid||p2<right){
        if(p1<mid&&p2<right){                               //如果左右两侧都没有遍历完
            if(arr[p1]<=arr[p2]){                           //如果左侧区间元素更小
                tmp[len++]=arr[p1++];                       //直接将左侧区间元素放入子串
            }else {                                         //如果右侧区间元素更小
                ans+=mid-p1;                                //则左侧从p1到mid-1的元素都大于右侧区间元素
                tmp[len++]=arr[p2++];                       //将右侧区间元素放入子串
            }
        }else if(p1<mid){                                   //左侧区间元素还没有遍历完
            tmp[len++]=arr[p1++];
        }else{                                              //右侧区间元素还没有遍历完
            tmp[len++]=arr[p2++];
        }
    }

    //放回完成排序
    for(int i=left;i<right;i++){
        arr[i]=tmp[i-left];
    }

 }

 int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //排序计算逆序对数
    mySort(arr,0,n);
    //输出
    cout<<ans;

    return 0;
 }