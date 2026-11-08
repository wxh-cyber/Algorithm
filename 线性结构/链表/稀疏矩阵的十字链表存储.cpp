#include <iostream>
using namespace std;

const int MAXN=100;

int m,n;

typedef struct OLNode{
    int row;
    int col;
    int val;
    struct OLNode *left,*right,*up,*down;
}OLNode,*OLink;

OLink createCrossList(int &m,int &n){
    int t;

    cout << "请输入非零元素的个数：" << endl;
    cin >> t;

    //创建总表头节点
    OLink head=new OLNode;
    head->row=m;
    head->col=n;
    head->right=head->down=nullptr;
    
    //创建行表头和列表头循环链表
    OLink *rowHead=new OLink[m+1];
    OLink *colHead=new OLink[n+1];
    for(int i=1;i<=m;i++){
        rowHead[i]=new OLNode;
        rowHead[i]->row=i;
        rowHead[i]->col=0;
        rowHead[i]->right=nullptr;
    }
    for(int j=1;j<=n;j++){
        colHead[j]=new OLNode;
        colHead[j]->row=0;
        colHead[j]->col=j;
        colHead[j]->down=nullptr;
    }

    cout << "请输入" << t << "个非零元素的三元组（行 列 值）：" << endl;
    for(int k=0;k<t;k++){
        int r,c,e;
        cin>>r>>c>>e;

        //创建新节点
        OLink p=new OLNode;
        p->row=r;
        p->col=c;
        p->val=e;
        p->right=p->down=nullptr;

        //插入到行链表（按列号有序）
        if(rowHead[r]->right==nullptr||rowHead[r]->right->col>c){
            //插入到行链表头部
            p->right=rowHead[r]->right;
            rowHead[r]->right=p;
        }else{
            //找到合适位置插入
            OLink q=rowHead[r];
            while(q->right!=nullptr&&q->right->col<c){
                q=q->right;
            }
            p->right=q->right;
            q->right=p;
        }

        //插入到列链表（按行号有序）
        if(colHead[c]->down==nullptr||colHead[c]->down->row>r){
            //插入到列链表头部
            p->down=colHead[c]->down;
            colHead[c]->down=p;
        }else{
            //找到合适位置插入
            OLink q=colHead[c];
            while(q->down!=nullptr&&q->down->row<r){
                q=q->down;
            }
            p->down=q->down;
            q->down=p;
        }
    }

    return head;
}

void print(OLink head,OLink *rowHead,int m,int n){
    cout << "十字链表表示的矩阵：" << endl;
    for(int i=1;i<=m;i++){
        OLink p=rowHead[i]->right;                    //指向该行的第一个非零元素
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
    OLink head=createCrossList(m,n);
    

    return 0;
}