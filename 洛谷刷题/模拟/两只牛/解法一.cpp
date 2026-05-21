/**
 *  @link https://www.luogu.com.cn/problem/P1518
 */
 #include<iostream>
using namespace std;

char map[12][12];
int farmer[3],cow[3];
int ans,tdz;
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
    if(direction==0) {
        if(map[x-1][y]=='*') {
            if(obj==0) farmer[0]=1;
            else cow[0]=1;
        }else {
            if(obj==0) farmer[1]--;
            else cow[1]--;
        }
    }else if(direction==1) {
        if(map[x][y+1]=='*') {
            if(obj==0) farmer[0]=2;
            else cow[0]=2;
        }else {
            if(obj==0) farmer[2]++;
            else cow[2]++;
        }
    }else if(direction==2) {
        if(map[x+1][y]=='*') {
            if(obj==0) farmer[0]=3;
            else cow[0]=3;
        }else {
            if(obj==0) farmer[1]++;
            else cow[1]++;
        }
    }else {
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
    while(pass()){
        tdz=farmer[1]+farmer[2]*10+cow[1]*100+cow[2]*1000+farmer[0]*10000+cow[0]*40000;
        if(appearance[tdz]) {
            cout<<0<<endl;
            return 0;
        }
        appearance[tdz]=1;
        move(farmer[1],farmer[2],farmer[0],0);
        move(cow[1],cow[2],cow[0],1);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}