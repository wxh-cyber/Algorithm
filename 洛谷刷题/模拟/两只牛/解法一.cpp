/**
 *  @link https://www.luogu.com.cn/problem/P1518
 */
 #include<iostream>
using namespace std;

char map[12][12];
//两个对象的下标0表示方向，1表示横坐标，2表示纵坐标
int farmer[3],cow[3];
int ans,tdz;
//是否能够相遇的数组
bool appearance[200000];

/**
 *  @brief 移动函数
 *  @param x 移动前的横坐标
 *  @param y 移动前的纵坐标
 *  @param direction 移动方向
 *  @param obj 移动对象
 *  @return 无返回值
 */
void move(int x,int y,int direction,int obj){
    //方向向北
    if(direction==0) {
        if(map[x-1][y]=='*') {
            //遇到障碍物，改变方向
            if(obj==0) farmer[0]=1;
            else cow[0]=1;
        }else {
            //可以移动，更新坐标
            if(obj==0) farmer[1]--;
            else cow[1]--;
        }
    }else if(direction==1) {                        //方向向东
        if(map[x][y+1]=='*') {
            if(obj==0) farmer[0]=2;
            else cow[0]=2;
        }else {
            if(obj==0) farmer[2]++;
            else cow[2]++;
        }
    }else if(direction==2) {                       //方向向南
        if(map[x+1][y]=='*') {
            if(obj==0) farmer[0]=3;
            else cow[0]=3;
        }else {
            if(obj==0) farmer[1]++;
            else cow[1]++;
        }
    }else {                                       //方向向西
        if(map[x][y-1]=='*') {
            if(obj==0) farmer[0]=0;
            else cow[0]=0;
        }else{
            if(obj==0) farmer[2]--;
            else cow[2]--;
        }
    }
}

/**
 *  @brief 判断是否相遇
 *  @param 无参数
 *  @return 可以相遇返回1，否则返回0
 */
bool pass(){
    //如果两个对象的位置相同，则可以相遇
    if(farmer[1]==cow[1]&&farmer[2]==cow[2]) return 0;
    else return 1;
}

int main(){
    //对数组边界进行初始化，即认为数组边界上的元素均为*
    for(int i=0;i<=11;i++) {
        map[i][0]=map[i][11]='*';
    }
    for(int i=1;i<=10;i++){
        map[0][i]=map[11][i]='*';
    }
    
    //输入实际的地图
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin>>map[i][j];
            if(map[i][j]=='F') {
                farmer[1]=i;
                farmer[2]=j;
            }
            if(map[i][j]=='C') {
                cow[1]=i;
                cow[2]=j;
            }
        }
    }

    //模拟时间的流逝
    while(pass()){
        /**
         *  思考：为什么此处采用tdz来记录两个对象的实际位置和方向？
         *     - 判断两者能否相遇的核心是：检测“无限死循环”（状态重复）
         *     - 如果农夫和奶牛在移动过程中，他们的位置、朝向曾经同时出现过一次，那么说明他们陷入了一个周期性的死循环，永远不可能相遇
         *     - 反之，只要不陷入死循环，因为状态是有限的，他们最终一定会相遇。
         *   
         *  一、什么是专属值（状态压缩）？
         *    tdz（专属值），它其实是把当前这一秒的所有游戏状态压缩成了一个唯一的整数。
         *        tdz=farmer[1]+farmer[2]*10+cow[1]*100+cow[2]*1000+farmer[0]*10000+cow[0]*40000;
         *
         *    这一行代码把5个维度的信息打包成了一个数字：
         *        - farmer[1]：农夫的行坐标（1~10），占个位
         *        - farmer[2]：农夫的列坐标（1~10），占十位
         *        - cow[1]：奶牛的行坐标（1~10），占百位
         *        - cow[2]：奶牛的列坐标（1~10），占千位
         *        - farmer[0]：农夫的朝向（0北1东2南3西），占万位
         *        - cow[0]：奶牛的朝向（0北1东2南3西），占四万位
         *    
         *  二、如何判断死循环？
         *    代码使用了一个布尔数组 appearance[200000] 来记录某个专属值是否出现过：
         *        if (appearance[tdz]){//死循环了就输出0并结束程序
         *            cout<<0<<endl;
         *            return 0;
         *        }
         *        appearance[tdz]=1;//标记
         *    每次循环开始，先计算当前的专属值 tdz。
         *    检查 appearance[tdz]：如果为 true，说明这个状态以前出现过！既然以前出现过，且当时没有相遇，那么按照相同的规则移动，接下来又会经历同样的轨迹，无限绕圈子，永远遇不到。此时直接输出 0 并结束程序。
         *    标记 appearance[tdz]=1：如果当前状态没出现过，就把它标记为已出现，供以后的轮次检查。
         *
         *  三、数组上限如何确定？
         *    根据状态总数计算的上限。
         *        - 行坐标最大是10
         *        - 列坐标最大是10
         *        - 朝向最大是3
         *    故专属值最大可能为：10+10*10+10*100+10*1000+3*10000+3*40000=161110；
         *    数组上限开200000。
         *
         *  四、为什么只要不死循环就一定能相遇？（数学原理）
         *    地图大小只有 10x10，朝向只有 4 种。
         *    农夫的状态有 10×10×4=400种。
         *    奶牛的状态有 10×10×4=400 种。
         *    两者组合起来的总状态数最多只有400×400=160000 种。
         *
         *    这意味着，游戏最多进行 160000 秒。
         *    如果过了 160000 秒还没相遇，根据抽屉原理，必然有某个状态重复了，也就必然会触发 if (appearance[tdz]) 输出 0。
         *    所以，只要程序不输出0，它就一定能在有限步数内走到 farmer[1]==cow[1] && farmer[2]==cow[2] 的情况并输出秒数。
         */
         /**
         *  思考：在生成专属值时，为什么对于前面的farmer[1]、farmer[2]、cow[1]、cow[2]、farmer[0]都是10的倍数，而cow[0]是40000的倍数？
         *    乘以 40000 是为了给奶牛的朝向 c[0] 腾出足够的“独立空间”，确保它不会和前面的状态（农夫坐标、奶牛坐标、农夫朝向）混淆。
         *    但严格来说，前面能产生的最大真实值，在当牛和农夫都位于（10，10），农夫朝向西（3）时，
         *    产生专属值是：10+10*10+10*100+10*1000+3*10000=41110，实际上还是存在一定的冲突风险。
         *    从严谨角度出发，应该乘一个更大的值，如50000。
         */
        tdz=farmer[1]+farmer[2]*10+cow[1]*100+cow[2]*1000+farmer[0]*10000+cow[0]*40000;
        if(appearance[tdz]) {
            cout<<0<<endl;
            return 0;
        }
        appearance[tdz]=1;
        //农民移动
        move(farmer[1],farmer[2],farmer[0],0);
        //牛移动
        move(cow[1],cow[2],cow[0],1);
        //记录时间
        ans++;
    }
    //输出结果
    cout<<ans<<endl;
    return 0;+
}