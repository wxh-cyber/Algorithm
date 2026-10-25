/**
 *  @link https://www.luogu.com.cn/problem/P1160
 */

 #include <iostream>
 using namespace std;

 const int MAXN=1e5+5;

 int n,m,x;                                                //n表示同学总数，m表示去除操作的次数，x表示每次移除的同学下标
 int k,p;                                                  //k表示插入操作时，参照的同学下标，p表示在左侧还是右侧插入
 int head;                                                 //头节点下标
 int pre[MAXN],nxt[MAXN];                                  //pre[x]表示下标x节点的前驱节点下标值，nxt[x]表示下标节点的后继结点的下标值
 bool alive[MAXN];                                         //该节点是否可被删除

 int main(){
    cin>>n;                                                //输入总人数

    head=1;                                                //定义头结点下标为1
    alive[1]=true;                                         //修改该节点状态为可以被删除

    for(int i=2;i<=n;i++){
        cin>>k>>p;                                         //每次插入操作，需要输入参考节点的下标和相对的左右关系
        alive[i]=true;                                     //设置下标为i的节点可以被删除

        /**
         *  @note 说明：
         *    在进行新节点的插入时，无论左右两侧节点是否为空，对于插入节点而言，都要更新其前驱和后继指向的节点下标。
         *    左右节点是否为空仅影响其指向插入节点的方式。
         */
        if(p==1){                                          //在参考节点右侧插入节点
            pre[i]=k;                                      //更新其前驱节点下标为k
            nxt[i]=nxt[k];                                 //更新其后继节点下标为原先的k节点对应的后继指向下标

            if(nxt[k]!=0){                           
                pre[nxt[k]]=i;                             //如果在插入前，k不是最后一个节点，则更新k的后继节点指向的前驱节点下标为i
                //由于本题解中仅设置了head头节点下标，没有tail尾节点下标，故不需要再进行多余操作
            }

            nxt[k]=i;                                      //更新参考节点k的后继节点下标为i
        }else{                                             //在参考节点左侧插入节点
            nxt[i]=k;                                      //更新插入节点的后继节点下标为k
            pre[i]=pre[k];                                 //更新插入节点的前驱节点下标为k的前驱节点下标

            if(pre[k]!=0){                                 
                nxt[pre[k]]=i;                             //如果参考节点不是第一个节点，则将其原先的前驱节点的后继节点下标更新为i
            }else{
                head=i;                                    //否则将头结点下标设置为i
            }

            pre[k]=i;                                      //无论参考节点是否为第一个节点，都需要将其前驱节点下标设置为i
        }
    }

    cin>>m;                                                //输入删除操作次数m
    while(m--){
        cin>>x;                                            //每次删除操作都输入对应的删除节点下标

        if(!alive[x])         
            continue;                                      //如果该节点已经被删除，则跳过本次操作

        if(pre[x]!=0){
            nxt[pre[x]]=nxt[x];                           //如果该节点不是头结点，则将该节点前驱节点的后继节点下标设置为被删除节点的后继节点下标
        }else{
            head=nxt[x];                                  //否则将头结点下标设置为被删除节点的后继节点下标
        }

        if(nxt[x]!=0){ 
            pre[nxt[x]]=pre[x];                           //如果被删除节点不是最后一个节点，则将被删除节点的后继节点的前驱节点下标设置为被删除节点的前驱节点下标
        }

        alive[x]=false;                                   //更新被删除节点状态
    }

    //输出最终结果
    for(int cur=head;cur!=0;cur=nxt[cur]){
        cout<<cur<<" ";
    }

    return 0;
 }