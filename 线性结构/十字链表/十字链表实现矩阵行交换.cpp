#include <iostream>
using namespace std;

const int MAXN=1e5;

int n,m;                                 //矩阵的行数、列数
int matrix[MAXN][MAXN];                  //二维数组存储矩阵

/**
 *  @brief Node - 链表节点
 *  @param {int} data - 节点数据
 *  @param {Node*} next - 节点指针
 */
struct Node{
    int data;
    Node *next;                          //指向下一个元素
};

/**
 *  @brief createRow - 创建单行
 *  @param {int[]} arr - 单行数据
 *  @param {int} m - 数据个数
 *  @return {Node*} head - 链表头结点 
 */
Node* createRow(int arr[],int m){
    Node *head=nullptr,*tail=nullptr;                        //初始时，head和tail均为nullptr
    for(int i=0;i<m;i++){
        Node *node=new Node{arr[i],nullptr};    //每遍历到一个数组中的数据就新建一个节点
        if(!head) {
            head=tail=node;                                 //如果头结点为空，则head和tail均指向node
        }else{
            tail->next=node;                                //尾插法
            tail=node;                                      //更新尾指针
        }
    }

    tail->next=head;                                          //循环链表
    return head;                                              //返回头结点
}

/**
 *  @brief swapRows - 交换矩阵的两行
 *  @param {Node*} row1 - 第一行
 *  @param {Node*} row2 - 第二行
 *  @return 无
 */
void swapRows(Node* &row1,Node* &row2){
    //交换两个链表的头指针
    Node* temp=row1;
    row1=row2;
    row2=temp;
}

/**
 *  @brief print - 输出十字链表
 *  @param {Node*} head - 行链表头指针
 *  @return 无
 */
void print(Node* head){
    if(!head) return;                                       //对head为空进行特判
    Node* temp=head;
    do{
        cout << temp->data << " ";                          //输出本节点数据
        temp = temp->next;                                  //指向下一个节点
    }while(temp!=head);

    cout<<endl;
}

int main(){
    cin>>n>>m;                                            //输入矩阵的行数列数
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];                            //输入矩阵数据
        }
    }

    //创建行链表数组
    Node *rows[MAXN];
    for(int i=0;i<n;i++){
        rows[i]=createRow(matrix[i],m);
    }

    // 输出原始矩阵
    cout << "原始矩阵：" << endl;
    for (int i = 0; i < n; ++i) {
        print(rows[i]);
    }

    // 交换第0行和第2行
    swapRows(rows[0], rows[2]);

    // 输出交换后的矩阵
    cout << "交换第0行和第2行后：" << endl;
    for (int i = 0; i < n; ++i) {
        print(rows[i]);
    }

    return 0;
}