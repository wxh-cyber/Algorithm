/**
 *  @link https://www.luogu.com.cn/problem/B4324
 */

#include <iostream>
using namespace std;

const int MAXN=5e5+5;

int n,m;
int op,x,y;
int head;
int pre[MAXN],nxt[MAXN];
bool alive[MAXN];

int main(){
    cin>>n;

    head=1;
    alive[1]=true;

    for(int i=2;i<=n;i++){
        alive[i]=true;
        
        pre[i]=i-1;
        nxt[i]=nxt[i-1];
        nxt[i-1]=i;
    }

    cin>>m;
    while(m--){
        cin>>op;
        
        if(op==1||op==2){
            cin>>x>>y;
        }else{
            cin>>x;
        }

        if(op==1||op==2){
            if(op==1&&nxt[x]==y) continue;
            if(op==2&&nxt[y]==x) continue;
        }else{
            if(!alive[x]) continue;
        }

        if(op==1){
            if(alive[x]==true){
                if(nxt[x]!=0){
                    pre[nxt[x]]=pre[x];
                }

                if(pre[x]!=0){
                    nxt[pre[x]]=nxt[x];
                }else{
                    head=nxt[x];
                }
            }else{
                alive[x]=true;
            }

            pre[x]=pre[y];
            nxt[x]=y;

            if(pre[y]!=0){
                nxt[pre[y]]=x;
            }

            pre[y]=x;
        }else if(op==2){
            if(alive[x]==true){
                if(nxt[x]!=0){
                    pre[nxt[x]]=pre[x];
                }

                if(pre[x]!=0){
                    nxt[pre[x]]=nxt[x];
                }else{
                    head=nxt[x];
                }
            }else{
                alive[x]=true;
            }

            pre[x]=y;
            nxt[x]=nxt[y];

            if(nxt[y]!=0){
                pre[nxt[y]]=x;
            }

            nxt[y]=x;
        }else{
            if(pre[x]!=0){
                nxt[pre[x]]=nxt[x];
            }else{
                head=nxt[x];
            }

            if(nxt[x]!=0){
                pre[nxt[x]]=pre[x];
            }

            alive[x]=false;
            pre[x]=0;
            nxt[x]=0;
        }

    }

    for(int cur=head;cur!=0;cur=nxt[cur]){
        cout<<cur<<" ";
    }
    
    return 0;
}