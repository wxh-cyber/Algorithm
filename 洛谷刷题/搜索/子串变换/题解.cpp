/**
 *  @link https://www.luogu.com.cn/problem/P1032
 */

 #include <iostream>
 #include <string>
 #include <vector>
 #include <unordered_set>
 using namespace std;

 const int MAXM=20;

 int n=1;                                                 //变换规则数量，至少有一条
 string a,b;                                              //初始字符串和目标字符串              
 string before[MAXM],after[MAXM];                         //变换规则数组

 /**
  *  @brief Node - 字符串节点
  *  @param {string} cur - 每次变换的字符串
  *  @param {int} count - 从初始变换到这个字符串的步数
  */
 struct Node{
    string cur;
    int count;
 };

 int main(){
    cin>>a>>b;                                            //输入初始字符串和结束字符串
    while(cin>>before[n]>>after[n]){                      //依次输入n条变换规则
        n++;   
    }
    n-=1;

    //如果初始状态下，初始字符串与目的字符串相同，则直接输出0
    if(a==b){ 
        cout<<0<<endl;
        return 0;
    }

    vector<Node> q;                                       //采用vector存储每个变换的状态
    unordered_set<string> visited;                        //采用set记录每个已经变换过的状态，确保不会重复

    q.push_back({a,0});                  //初始状态加入q
    visited.insert(a);                               //更新set的记录

    size_t head=0;                                       //遍历q的指针下标，初始为0

    /**
     *  @note
     *    由于head从前往后单调方向遍历，因此实际上也实现了队列的功能。
     */
    while(head<q.size()){                                
        Node now=q[head++];                              //获取当前head指向的节点，为now

        if(now.cur==b){
            cout<<now.count<<endl;                       //如果当前节点的字符串已经为b，直接输出对应步数并返回
            return 0;
        }

        if(now.count==10){
            continue;                                    //若当前步数已经达到10，且不是b，则跳过当前状态
        }

        for(int i=1;i<=n;i++){                           //依次遍历n条转换规则
            //记录当前节点找到子字符串的下标为pos
            size_t pos=now.cur.find(before[i],0);

            //如果没有遍历到string::npos，则说明找到了至少一个子字符串
            while(pos!=string::npos){
                string next=now.cur;                     //拷贝一份原先的字符串
                //将原先字符串的子字符串部分按照规则进行转换
                /**
                 *  @note
                 *    replace(替换的初始下标，被替换的子字符串长度，替换后的字符串)
                 */
                next.replace(pos,before[i].size(),after[i]);

                /**
                 *  @note
                 *    visited.insert(next) 会尝试把 next 插入 visited，并返回一个结果，其中：
                 *      - .first 是指向集合中该元素的迭代器；
                 *      - .second 是布尔值：这次是否真的插入了新元素。
                 *
                 *    此处条件判断表示next是第一次出现。
                 */
                if(visited.insert(next).second){
                    int nextCount=now.count+1;                           //变换到next的次数为nextCount

                    if(next==b){                                         //如果next恰好为b，则直接输出对应的步数
                        cout<<nextCount<<endl;
                        return 0;
                    }

                    //否则将next和对应步数加入vector
                    q.push_back({next,nextCount});
                }

                //下一次寻找从当前pos的后面一位开始寻找
                pos=now.cur.find(before[i],pos+1);

            }
        }
    }

    //如果搜索完毕，依然没有对饮结果，则输出NO ANSWER!
    cout << "NO ANSWER!" << endl;

    return 0;
 }