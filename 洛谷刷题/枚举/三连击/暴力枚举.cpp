/**
 *  @link https://www.luogu.com.cn/problem/P1008
 */
 #include <cstdio>
 #include <cstring>
 using namespace std;

 int n;
 bool used[10];

 int main(){
    /**
     *  思考：为什么是从192开始？
     *  答：对本题进行分析，由于题目要求将1-9这几个数分为3个三位数，且构成1:2:3的比例，那么实际上可以先推理出第一个三位数的最大值和最小值。
     *      根据题目的组成规则可知，第一个三位数的最小值为123。
     *      同时反向可知，最后一个三位数的最大值为987。
     *      987÷3=329，因此第一个三位数的最大值为329。
     *      但实际上来说，如果知道最终答案，那么直接从192-327的区间内枚举即可。
     */
    for(int i=192;i<=327;i++){
        memset(used,false,sizeof(used));
        n=0;                                      //每次迭代，都需要将n清零

        used[i%10]=used[i/10%10]=used[i/100]=used[i*2%10]=used[i*2/10%10]=used[i*2/100]=used[i*3%10]=used[i*3/10%10]=used[i*3/100]=true;

        for(int j=1;j<=9;j++){
            if(used[j]) n++;
        }

        //如果齐了，就输出
        if(n==9) printf("%d %d %d\n",i,i*2,i*3);
    }

    return 0;
 }