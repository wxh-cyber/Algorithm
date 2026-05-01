## STL容器

<hr />

### ``set``和``multiset``有什么区别？

``set`` 和 ``multiset`` 都是 C++ STL 里的关联容器，底层通常都是红黑树，元素会自动按序排列。

它们最核心的区别只有一个：

- ``set``：**元素不能重复**
- ``multiset``：**元素可以重复**

<hr />

#### 头文件
```cpp
#include<set>
```
``set`` 和 ``multiset`` 都在这个头文件里。

<hr />

#### 定义方式
```cpp
set<int> s;
multiset<int> s;
```

<hr />

#### 插入时的区别

**``set``插入**：
```cpp
auto res=s.insert(5);
```
返回值是一个 ``pair``：
- ``res.first``：指向元素位置的迭代器
- ``res.second``：是否插入成功

例如：
```cpp
if(res.second){
    cout<<"插入成功"<<endl;
}else {
    cout<<"插入失败"<<endl;
}
```

<br />

**``multiset``插入**：
```cpp
ms.insert(5);
```
因为允许重复，所以一般不存在“插入失败因为重复”的说法。

<hr />

#### 查找时的区别
两者都可以：
```cpp
find(x);
count(x);
```
但 ``count(x)`` 的意义不同：

``set``
- 结果只能是 ``0`` 或 ``1``

``multiset``
- 结果可能是 ``0,1,2,3...``

例如：
```cpp
set<int> s={1,2,3};
cout<<s.count(2);       //1
cout<<s.count(5);       //0
```
```cpp
multiset<int> ms={1,2,2,2,3};
cout<<ms.count(2);      //3
```

<hr />

#### 删除时的区别

**set**
```cpp
s.erase(2);
```
删除值为 2 的元素，因为最多只有一个。

<br />

**multiset**
```cpp
ms.erase(2);
```
会把**所有值为 2 的元素全部删除**。

如果只想删一个，要这样写：
```cpp
//ms.find(2)会在multiset中查找值为2的元素
//因为 multiset 允许重复元素，如果存在多个 2，C++ 标准规定 find 会返回指向第一个遇到的 2 的迭代器（由于底层是红黑树，实际上是按中序遍历的第一个 2）。
//如果没找到 2，它会返回 ms.end()。
//auto it 自动推导出迭代器的类型。
auto it=ms.find(2);
//这是一个安全检查（防御性编程）。
//为什么要检查？因为如果 find 没找到，it 就是 end()。如果直接对 end() 执行删除操作，会导致未定义行为（通常是程序崩溃）。
if(it!=ms.end()) ms.erase(it);
```
将只会删除一个 2。

<hr />

#### 排序规则
默认都是**从小到大**：
```cpp
set<int> s;
multiset<int> ms;
```
如果想从大到小：
```cpp
set<int, greater<int>> s;
multiset<int, greater<int>> ms;
```

### ``set``和``multiset``的常用算法模板

<br />

#### 模板1：``set``去重并排序
```cpp
#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    int n,x;
    cin>>n;                     //输入元素总数
    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(x);            //存入集合中
    } 

    for(int v:s)
    cout<<v<<" ";             //输出集合中的元素
    return 0;
}
```
用途：
- 输入一堆数，去重后从小到大输出

