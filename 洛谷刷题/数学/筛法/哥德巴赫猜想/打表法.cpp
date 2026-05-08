/**
 *    @link https://www.luogu.com.cn/problem/P1304
 */
 #include<iostream>
 #include<cstdio>
 #include<vector>
 using namespace std;
 
 int n;
 const int v[10005]={0};
 vector<int> prime;

 //从2-10000中找出所有的质数
 int Eratosthenes(int n){
    int i,j,k=0;
    v[0]=v[1]=1;        //实际上，严格来讲，1既不是质数，也不是合数，但是此处为了仅区分出质数，因此将0和1均标记为1
    for(i=2;i<=n;i++){
        if(v[i]==0){
            prime.push_back(i);
            k++;
        }
        for(j=i*2;j<=n;j+=i){
            v[j]=1;
        }
    }
    return k;
 }

 //对一个数进行分解，输出分解的结果
 /**
 *  思考：为什么print这样输出，不会出现重复的情况呢？
 *  答：因为在单个的条件判断中，如果符合条件，在输出的同时就会return。
 *  因此，在print函数中，只要某个数存在被拆解的情况，那么就有且仅有一行输出结果。
 *  此外，由于外层的i从小到大开始遍历，因此，在输出某个特定的组合的时候，由于已经return，所以不会出现i和a1-i颠倒的情况。
 */
 void print(int num){
    for(int i=0;i<1299;i++){
        for(int j=0;j<1299;j++){
            if(prime[i]+prime[j]==num){
                printf("%d=%d+%d\n",num,prime[i],prime[j]);
                return;
            }
        }
    }
 }

 int main(){
    scanf("%d",&n);
    for(int i=4;i<=n;i+=2){
        print(i);
    }

    return 0;
 }