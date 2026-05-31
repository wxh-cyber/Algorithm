/**
 *  @link https://www.luogu.com.cn/problem/P1249
 *  @note 本题详细推导过程请见随后的手写笔记
 */
 #include <iostream>
 using namespace std;

 int a[10001]={};
 int s[10001]={};
 int n,len=1;

 void mul(int x){
    for(int i=1;i<=len;i++){
        s[i]*=x;
    }
    for(int i=1;i<=len;i++){
        s[i+1]+=s[i]/10;
        s[i]%=10;
    }
    while(s[len+1]>0){
        len++;
        s[len+1]+=s[len]/10;
        s[len]%=10;
    }
 }
 int main(){
    cin>>n;
    //分别对3和4进行特判
    if(n==3) {
        cout<<3<<endl;
        cout<<3<<endl;
        return 0;
    }
    if(n==4) {
        cout<<4<<endl;
        cout<<4<<endl;
    }

    s[0]=s[1]=1;
    int Sum=0,tot=0;
    for(int i=2;Sum<n;Sum+=i,i++){
        a[++tot]=i;
    }
    if(Sum>n+1){
        a[Sum-n-1]=0;
    }else if(Sum==n+1){
        a[tot]++;
        a[1]=0;
    }
    
    for(int i=1;i<=tot;i++){
        if(a[i]){
            cout<<a[i]<<" ";
            mul(a[i]);
        }
    }
    cout<<endl;
    for(int i=len;i>=1;i--){
        cout<<s[i];
    }
    cout<<endl;

    return 0;
 }