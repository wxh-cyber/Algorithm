/**
 *  @link https://www.luogu.com.cn/problem/P1160
 */

 #include <iostream>
 #include <cstdio>
 using namespace std;

 const int MAXN=1e5+5;

 int n,m,x;                                            //n表示同学总数，m表示去除操作的次数，x表示每次移除的同学下标
 int k,p;                                              //k表示插入操作时，参照的同学下标，p表示在左侧还是右侧插入

 /**
  *  @brief Node - 单个节点
  *  @param int val - 同学编号
  *  @param *Node prev - 前驱指针
  *  @param *Node next - 后继指针
  */
 struct Node{
    int val;                                         
    Node *prev;
    Node *next;
 };
 
 Node* pos[MAXN];                                     //pos指针数组用于索引查询

 int main(){
    cin>>n;                                          //输入总人数
    Node *head=new Node{1,nullptr,nullptr};              //创建第一个节点，并让头指针指向头节点
    Node *tail=head;                                                      //初始状态下，尾指针和头指针指向同一个节点
    pos[1]=head;                                                          //将这个节点存入指针数组

    for(int i=2;i<=n;i++){
        cin>>k>>p;                                                        //输入参考同学的下标k和相对于其的左右关系p
        Node *point=pos[k];                                               //从指针数组中获取对应的节点，并标记为point
        Node *node=new Node{i,nullptr,nullptr};          //新建节点
        pos[i]=node;                                                      //每次新建的节点都要存入对应的指针数组

        /**
         *  @note 说明：
         *    在进行新节点的插入时，无论左右两侧节点是否为空，对于插入节点node而言，都要更新其前驱和后继指针。
         *    左右节点是否为空仅影响其指向node节点的方式。
         */
        if(p==1){                                                         //将i插入到k的右侧
            node->prev=point;                                             //将node的前驱指针指向参考节点
            //若参考节点的下一个节点非空，则正常指向这个节点；若参考节点本身已经是最后一个节点了，则node的后继指针实际指向nullptr                     
            node->next=point->next;                                       //将node的后继指针指向参考节点的下一个节点

            if(point->next!=nullptr){
                point->next->prev=node;                                   //若参考节点本身不是最后一个节点，则将下一个节点的前驱指针指向node
            }else {
                tail=node;                                                //若参考节点本身已经是最后一个节点了，则node插入后，将尾指针更新为node节点
            }

            point->next=node;                                             //无论在插入前，参考节点本身是否为最后一个节点，都应该将参考节点的后继指针指向node

        }else {                                                          //将i插入到k的左侧
            node->prev=point->prev;                                      //将node的前驱指针指向参考节点的前一个节点
            node->next=point;                                            //将node的后继指针指向参考节点

            if(point->prev!=nullptr){                                    
                point->prev->next=node;                                  //若参考节点本身不是第一个节点，则将前一个节点的后继指针指向node
            }else{
                head=node;                                               //否则将头指针指向node
            }

            point->prev=node;                                            //无论在插入前，参考节点本身是否为第一个节点，都应该将参考节点的前驱指针指向node
        }
    }

    cin>>m;                                                              //输入删除操作次数m
    for(int i=0;i<m;i++){
        cin>>x;                                                          //每次操作输入删除的节点下标
        Node *point=pos[x];                                              //point指向对应的节点
        
        if(point==nullptr){                                              //如果该节点已经被删除，则跳过本次操作
            continue;
        }

        if(point->prev!=nullptr){
            point->prev->next=point->next;                               //如果被删除节点不是第一个节点，则将其前面一个节点的后继指针指向被删除节点的下一个节点
        }else {
            head=point->next;                                            //如果被删除节点已经是第一个节点，那么显然被删除后，被删节点的下一个节点成为头节点，用head指向对应节点
        }

        if(point->next!=nullptr){
            point->next->prev=point->prev;                               //如果被删除节点不是最后一个节点，那么将其后继节点的前驱指针指向被删除节点的前面一个节点            
        }else{
            tail=point->prev;                                            //否则将尾指针指向被删除节点的前一个节点
        }

        delete point;                                                    //释放被删除节点的内存空间
        pos[x]=nullptr;                                                  //更新对应的指针状态
    }

    Node *point=head;                                                    //从头结点开始往后遍历输出最终结果
    while(point!=nullptr){
        printf("%d ",point->val);
        point=point->next;
    }

    return 0;
 }