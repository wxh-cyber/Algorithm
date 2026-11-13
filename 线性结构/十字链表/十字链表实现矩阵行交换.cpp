#include <iostream>
using namespace std;

const int MAXN=1e5;

int n,m;
int matrix[MAXN][MAXN];

struct Node{
    int data;
    Node *next;                          //指向下一个元素
};

Node* createRow(int arr[],int m){
    Node *head=nullptr,*tail=nullptr;
    for(int i=0;i<m;i++){
        Node *node=new Node{arr[i],nullptr};
        if(!head) {
            head=tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
    }

    tail->next=head;                                          //循环链表
    return head;                                              //返回头结点
}

void swapRows(Node* &row1,Node* &row2){
    //交换两个链表的头指针
    Node* temp=row1;
    row1=row2;
    row2=temp;
}

void print(Node* head){
    if(!head) return;                                       //对head为空进行特判
    Node* temp=head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp!=head);

    cout<<endl;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
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