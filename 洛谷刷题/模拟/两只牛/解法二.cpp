/**
 *  @link https://www.luogu.com.cn/problem/P1518
 */
 #include<iostream>
 using namespace std;

 char map[15][15];                                   //存放地图的数组

 //方向数组：0北，1东，2南，3西
 int dx[]={-1,0,1,0};
 int dy[]={0,1,0,-1};

 int fx,fy,fdir;                                     //农夫坐标和朝向
 int cx,cy,cdir;                                     //牛坐标和朝向
 int cnt=0;                                          //记录时间

 //记录状态是否出现过
 bool visited[15][15][5][15][15][5];
/**
 *  @brief 移动函数
 *  @param x 移动前的横坐标
 *  @param y 移动前的纵坐标
 *  @param dir 移动方向
 *  @return 无返回值
 */
 void move(int &x,int &y,int &dir) {
     int nx=x+dx[dir];
     int ny=y+dy[dir];

     //如果前方越界或遇到障碍物，右转
     if(nx<0||nx>=10||ny<0||ny>=10||map[nx][ny]=='*') {
        dir=(dir+1)%4;                               //右转90度
     }else {                                         //直走
        x=nx;
        y=ny;
     }
 }

 int main(){
    //读入地图
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin>>map[i][j];

            if(map[i][j]=='F'){
                fx=i;
                fy=j;
                fdir=0;                              //初始方向为北
                map[i][j]='.';                       //将农夫位置设为空地
            }else if(map[i][j]=='C'){
                cx=i;
                cy=j;
                cdir=0;                              //初始方向为北
                map[i][j]='.';
            }
        }
    }

    while(true) {
        //判断是否相遇
        if(fx==cx&&fy==cy) {
            cout<<cnt<<endl;
            return 0;
        }

        //判断是否陷入死循环（状态判重）
        if(visited[fx][fy][fdir][cx][cy][cdir]) {
            cout<<0<<endl;                           //状态重复，永远遇不到
            return 0;
        }

        visited[fx][fy][fdir][cx][cy][cdir]=true;    //标记当前状态

        //依次移动
        move(fx,fy,fdir);
        move(cx,cy,cdir);

        cnt++;
    }
    cout<<cnt<<endl;

    return 0;
 }