/**
 *  @link https://www.luogu.com.cn/problem/P1996
 */
 #include <cstdio>
 using namespace std;

 int n,m;                                         //n表示总人数，m表示特定的报数

 struct Node{                                     //一个节点包括了当前下标和指向下一个节点的指针
    int val;
    Node *next;
 };

 int main(){
    scanf("%d %d",&n,&m);                  //输入总人数和特定报数
    Node *head=new Node{1,nullptr},*tail=head;                //建立头结点，初始状态下，尾节点指针指向头结点
    for(int i=2;i<=n;i++){                                              
        tail->next=new Node{i,nullptr};                       //不断在当前尾节点后接上其他节点
        tail=tail->next;                                                 //保证尾指针始终指向最后一个节点
    }
    tail->next=head;                                                     //最后将尾节点的指针指向头结点，成环

    Node *prev=tail,*cur=head;                                           //单循环链表通过前驱指针保存当前节点前面的一个节点
    for(int i=1;i<=n;i++){                                               //由于最终所有人都需要出队，故外层循环为n
        for(int j=1;j<m;j++){                     //由于初始状态下的cur指针指向的人，报数为1，故移动m-1次后，cur指向的人报数一定为m
            prev=cur;                             //每次移动都更新prev和cur指针
            cur=cur->next;
        }

        printf("%d ",cur->val);            //输出报数为m的人的下标
        prev->next=cur->next;                     //删除这个节点
        delete cur;
        cur=prev->next;                           //cur指针指向原先被删除节点的下一个节点
    }

    return 0;
 }