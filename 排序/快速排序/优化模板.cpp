#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename RandomIt>
void insertion_sort(RandomIt first,RandomIt last){
    //如果加工数组的长度小于等于1，直接返回
    if(first==last) return;

    for(RandomIt i=first+1;i<last;i++){
        auto key=*i;
        RandomIt j=i-1;
        while(j>=first&&)
    }
}

int main(){
    

    return 0;
}