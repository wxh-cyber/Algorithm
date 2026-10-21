/**
 *  @link https://www.luogu.com.cn/problem/P1996
 */

 #include <cstdio>
 #include <list>
 using namespace std;

 int n,m;                                     //n表示总人数，m表示特定的报数 
 list<int> l;                                 //l表示list列表，用来存放所有人

 int main(){
    scanf("%d %d",&n,&m);             //输入总人数和特定报数
    for(int i=1;i<=n;i++){
        l.push_back(i);                  //依次将所有人都加入列表
    }

    auto it=l.begin();             //it指向list中的第一个对象
    while(!l.empty()){                       //当列表非空时
        for(int i=1;i<m;i++){                //经过m-1次移动，必然能够保证it指向的人的报数为m
            if(++it==l.end()) {              //如果it在移动前已经指向列表末尾的人，则下一次移动从列表头部开始遍历
                it=l.begin();
            }
        }

        printf("%d ",*it);            //输出报数为m的人的下标
        it=l.erase(it);                //释放这个人的内存空间，具体请参照本目录的思考部分
        if(it==l.end()) {                    //如果删除的已经是最后一个人，则让it指向列表头部
            it=l.begin();
        }
    }

    return 0;
 }