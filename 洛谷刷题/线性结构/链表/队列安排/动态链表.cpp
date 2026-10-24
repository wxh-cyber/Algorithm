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

        if(p==1){                                                         //将i插入到k的右侧
            node->prev=point;
            node->next=point->next;

            if(point->next!=nullptr){
                point->next->prev=node;
            }else {
                tail=node;
            }

            point->next=node;

        }else {                                                          //将i插入到k的左侧
            node->prev=point->prev;
            node->next=point;

            if(point->prev!=nullptr){
                point->prev->next=node;
            }else{
                head=node;
            }

            point->prev=node;
        }
    }

    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        Node *point=pos[x];
        
        if(point==nullptr){
            continue;
        }

        if(point->prev!=nullptr){
            point->prev->next=point->next;
        }else {
            head=point->next;
        }

        if(point->next!=nullptr){
            point->next->prev=point->prev;
        }else{
            tail=point->prev;
        }

        delete point;
        pos[x]=nullptr;
    }

    Node *point=head;
    while(point!=nullptr){
        printf("%d ",point->val);
        point=point->next;
    }

    return 0;
 }