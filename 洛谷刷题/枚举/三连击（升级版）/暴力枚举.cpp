/**
 *  @link https://www.luogu.com.cn/problem/P1618
 */
 
 #include <iostream>
 using namespace std;

 int a[10];                                               //映射数组，用于统计数字出现的次数
 int k1,k2,k3;                                            //表示三个数的比例
 int b1,b2,b3;                                            //表示三个数
 int ans;                                                 //统计符合条件的个数
 bool flag;                                               //标记是否满足条件，为false表示满足条件，否则不满足条件


 int main(){
    cin>>k1>>k2>>k3;                                      //输入三个数的比例
    for(int b=1;b<=1000/k3;b++){
        //求出三个数
        b1=b*k1;
        b2=b*k2;
        b3=b*k3;

        //如果b2或b3超过三位数，跳出循环
        if(b2>999||b3>999){
            break;
        }

        //统计b1中出现的所有数字
        for(int i=1;i<=3;i++){
            a[b1%10]++;
            b1/=10;
        }

        //统计b2中出现的所有数字
        for(int i=1;i<=3;i++){
            a[b2%10]++;
            b2/=10;
        }

        //统计b3中出现的所有数字
        for(int i=1;i<=3;i++){
            a[b3%10]++;
            b3/=10;
        }

        for(int i=1;i<=9;i++){                            //逐个遍历映射数组
            if(a[i]!=1) {                                 //如果有数字出现次数不为1，说明不满足条件
               flag=true;                                 //不满足条件时，将flag标记为true
               break;
            }
        }

        for(int i=1;i<=9;i++){                            //首先清空映射数组的状态
            a[i]=0;
        }

        if(!flag) {                                       //如果满足条件，输出结果
            cout<<b*k1<<" "<<b*k2<<" "<<b*k3<<endl;
            ans++;                                        //实际上本题并没有要求输出个数，ans在这里只是为了之后无解的情况而存在的
        }else{
            flag=false;                                   //不满足条件时，将flag重置
        }
    }

    //判断无解情况
    if(!ans){
        cout<<"No!!!";
    }
    
    return 0;
 }