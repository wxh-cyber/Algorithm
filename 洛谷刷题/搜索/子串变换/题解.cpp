/**
 *  @link https://www.luogu.com.cn/problem/P1032
 */

 #include <iostream>
 #include <string>
 using namespace std;

 const int MAXN=1e5+5;
 const int MAXM=20;

 int n=1;
 int head=0,tail=1;
 string a,b;
 string before[MAXM],after[MAXM];

 struct node{
    string cur;
    int count;
 }q[MAXN];

 int main(){
    cin>>a>>b;
    while(cin>>before[n]>>after[n]){
        n++;
    }
    n-=1;

    if(a==b){
        cout<<"NO ANSWER!"<<endl;
        return 0;
    }

    q[tail].cur=a;
    q[tail].count=0;
    while(head<tail){
        head++;

        for(int i=1;i<=n;i++){
            int pos=q[head].cur.find(before[i],0);
            while(1){
                if(pos==-1) break;
                else{
                    tail++;
                    q[tail].cur=q[head].cur;
                    q[tail].count=q[head].count+1;
                    q[tail].cur.replace(pos,before[i].size(),after[i]);

                    if(q[tail].cur==b){
                        cout<<q[tail].count;
                        return 0;
                    }

                    pos=q[head].cur.find(before[i],pos+1);
                }
            }
        }
    }

    return 0;
 }