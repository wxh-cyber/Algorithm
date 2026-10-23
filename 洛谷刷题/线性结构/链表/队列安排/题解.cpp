/**
 *  @link https://www.luogu.com.cn/problem/P1160
 */

 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 using namespace std;

 const int MAXN=1e5+5;

 int n,m,x;
 int k,p;

 struct Node{
    int val;
    Node *prev;
    Node *next;
 };

 int main(){
    cin>>n;
    Node *head=new Node{1,nullptr,nullptr};
    Node *tail=head;
    for(int i=2;i<=n;i++){
        cin>>k>>p;
        Node *point=head;
        if(point->val!=k&&point->next!=nullptr) {
            point=point->next;
        }

        if(p==1){
            if(k!=tail->val){
                Node *node=new Node{i,point,point->next};
                point->next->prev=node;
                point->next=node;
            }else {
                Node *node=new Node{i,point,nullptr};
                point->next=node;
                tail=node;
            }
        }else {
            if(k!=head->val){
                Node *node=new Node{i,point->prev,point};
                point->prev->next=node;
                point->prev=node;
            }else {
                Node *node=new Node{i,nullptr,point};
                point->prev=node;
                head=node;
            }
        }
    }

    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        Node *point=head;
        if(point->val!=x) {
            point=point->next;
        }
        if(point==nullptr) continue;

        if(point->prev!=nullptr){
            point->prev->next=point->next;
        }else {
            
        }
        
        else if(tail->val==x){
            if(tail->prev!=nullptr){
                tail=tail->prev;
                point->prev->next=nullptr;
            }else {
                delete tail;
                head=nullptr;
                tail=nullptr;
            }
        }else{
            point->prev->next=point->next;
            point->next->prev=point->prev;
            delete point;
        }
    }

    Node *point=head;
    while(point!=nullptr){
        printf("%d ",point->val);
        point=point->next;
    }

    return 0;
 }