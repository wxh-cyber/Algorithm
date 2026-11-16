#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

template<typename T,typename F>
int bidirectionalBFS(T start,T end,F getNeighbors){
    if(start==end) return 0;

    unordered_map<T,int> distStart,distEnd;
    queue<T> qStart,qEnd;

    distStart[start]=0;
    distEnd[end]=0;
    qStart.push(start);
    qEnd.push(end);

    
}

int main(){


    return 0;
}