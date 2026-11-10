#include <iostream>
using namespace std;

const int MAXN=100;

int m,n;

typedef struct OLNode{
    int row;                                    //行数
    int col;                                    //列数
    int val;                                    //非零元素值
    struct OLNode *right,*down;                 //单向指针
}OLNode,*OLink;

/**
 *  @brief createNode - 创建节点
 *  @param {int} r - 行下标
 *  @param {int} c - 列下标
 *  @param {int} v - 元素值
 *  @return {OLink} p - 创建的节点
 */
OLink createNode(int r,int c,int v){
    OLink p=new OLNode;                        //开辟一个新的内存空间
    p->row=r;
    p->col=c;
    p->val=v;
    p->right=p->down=nullptr;                 //初始时，right和down均指向nullptr
    return p;
}

/**
 *  @brief insertToRow - 插入到行链表（按列号有序）
 *  @param {OLink} rowHead - 行链表
 *  @param {OLink} p - 节点p
 *  @return 无
 */
void insertToRow(OLink &rowHead,OLink p){
    if(rowHead==nullptr||rowHead->col>p->col){                    //如果初始状态下行链表为空，或者p的列下标比任意一个节点列下标都小，则插在首部
        p->right=rowHead;
        rowHead=p;                                                //更新行链表首部为p节点地址
    }else{                  
        //否则插入到其他地方
        OLink q=rowHead;
        //q将遍历到列下表小于p的最大的节点
        while(q->right!=nullptr&&q->right->col<p->col){
            q=q->right;
        }
        //p插入到q节点后面
        p->right=q->right;
        q->right=p;
    }
}

/**
 *  @brief insertToCol - 插入到列链表（按行号有序）
 *  @param {OLink} colHead - 列链表
 *  @param {OLink} p - 节点p
 *  @return 无
 *  @note 插入思路和行链表类似，不再赘述
 */
void insertToCol(OLink &colHead,OLink p){
    if (colHead == nullptr || colHead->row > p->row) {
        p->down = colHead;
        colHead = p;
    } else {
        OLink q = colHead;
        while (q->down != nullptr && q->down->row < p->row) {
            q = q->down;
        }
        p->down = q->down;
        q->down = p;
    }
}

/**
 *  @brief print - 输出矩阵
 *  @param {OLink} rowHead - 行链表
 *  @param {int} m - 行数
 *  @param {int} n - 列数
 *  @return 无
 */
void print(OLink *rowHead,int m,int n){
    cout << "十字链表表示的矩阵：" << endl;
    for(int i=1;i<=m;i++){
        OLink p=rowHead[i];                    //指向该行的第一个非零元素
        for(int j=1;j<=n;j++){
            if(p!=nullptr&&p->col==j){
                cout << p->val << " ";
                p = p->right; // 移动到下一个非零元素
            }else{
                cout<<"0 ";
            }
        }

        cout<<endl;
    }
}

int main(){
    cout<<"请输入行数列数："<<endl;
    cin>>m>>n;
    
    //创建行表头和列表头数组
    OLink *rowHead=new OLink[m+1];
    OLink *colHead=new OLink[n+1];

    //初始化表头
    for(int i=1;i<=m;i++){
        rowHead[i]=nullptr;
    }
    for(int j=1;j<=n;j++){
        colHead[j]=nullptr;
    }

    //添加非零元素
    OLink p1 = createNode(1, 1, 5);
    insertToRow(rowHead[1], p1);
    insertToCol(colHead[1], p1);
    
    OLink p2 = createNode(1, 3, 8);
    insertToRow(rowHead[1], p2);
    insertToCol(colHead[3], p2);
    
    OLink p3 = createNode(2, 2, 9);
    insertToRow(rowHead[2], p3);
    insertToCol(colHead[2], p3);
    
    OLink p4 = createNode(3, 1, 6);
    insertToRow(rowHead[3], p4);
    insertToCol(colHead[1], p4);
    
    // 输出矩阵
    print(rowHead, m, n);

    //释放内存
    for (int i = 1; i <= m; ++i) {
        OLink p = rowHead[i];
        while (p != nullptr) {
            OLink temp = p;
            p = p->right;
            delete temp;
        }
    }
    delete[] rowHead;
    delete[] colHead;

    return 0;
}