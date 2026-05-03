## ``set``和``multiset``

<hr />

### ``set``和``multiset``中的内置方法
``std::set`` 和 ``std::multiset`` 都是 C++ STL 里的关联容器，底层通常是红黑树。

<hr />

#### 一、插入
**1. ``insert``**
作用：插入元素 ``x``

- ``set`` 返回：``pair<iterator, bool>``
- ``multiset`` 返回：``iterator``
```cpp
s.insert(10);
ms.insert(10);
ms.insert(10);
```
说明：

- ``set`` 中重复值插不进去
- ``multiset`` 可以重复插入

<br />

**2. ``emplace(args...)``**
作用：原地构造元素，效率通常更高

- 返回值规则和 ``insert()`` 类似
```cpp
s.emplace(20);
ms.emplace(20);
```

<br />

**3. ``emplace_hint(pos, x)``**
作用：带提示位置插入

- 返回插入位置迭代器
```cpp
s.emplace_hint(s.begin(), 5);
```

<hr />

#### 二、删除
**1. ``erase(x)``**
作用：删除值为 ``x`` 的元素

- 返回删除的元素个数
```cpp
s.erase(10);    // 0 或 1
ms.erase(10);   // 可能删除多个 10
```
说明：

- ``set`` 最多删一个
- ``multiset`` 会把所有等于 ``x`` 的都删掉

<br />

**2. ``erase(it)``**
作用：删除迭代器 ``it`` 指向的元素
```cpp
auto it = s.find(20);
if (it != s.end()) s.erase(it);
```
对于 ``multiset``，如果只想删一个重复值，用这个最合适。

<br />

**3. ``clear()``**
作用：清空容器

- 返回值：无
```cpp
s.clear();
ms.clear();
```

<hr />

#### 三、查找
**1. ``find(x)``**
作用：查找元素 ``x``

- 返回：指向该元素的迭代器；找不到返回 ``end()``
```cpp
auto it = s.find(15);
if (it != s.end()) cout << "found";
```

<br />

**2. ``count(x)``**
作用：统计 ``x`` 的个数

- 返回：``size_type``
```cpp
cout << s.count(10) << endl;   // 0 或 1
cout << ms.count(10) << endl;  // 可能大于 1
```

<br />

**3. ``contains(x)`` C++20**
作用：判断是否包含元素

- 返回：``bool``
```cpp
if (s.contains(10)) cout << "yes";
```
如果编译器较旧，可以用 ``find()`` 代替。

<hr />

#### 四、范围查找
**1. ``lower_bound(x)``**
作用：返回第一个 ``>= x`` 的位置

- 返回：迭代器
```cpp
auto it = s.lower_bound(10);
```

<br />

**2. ``upper_bound(x)``**
作用：返回第一个 ``> x`` 的位置

- 返回：迭代器
```cpp
auto it = s.upper_bound(10);
```

<br />

**3. ``equal_range(x)``**
作用：返回值等于 x 的区间

- 返回：``pair<iterator, iterator>``
```cpp
auto p = ms.equal_range(10);
for (auto it = p.first; it != p.second; ++it) {
    cout << *it << " ";
}
```
对 ``multiset`` 很常用，因为它能一次拿到所有重复元素范围。

<hr />

#### 五、容量
**1. ``size()``**
作用：返回元素个数
```cpp
cout << s.size();
```

<br />

**2. ``empty()``**
作用：判断是否为空

- 返回：``bool``
```cpp
if (s.empty()) cout << "empty";
```

<br />

**3. ``max_size()``**
作用：返回理论最大可存元素数
```cpp
cout << s.max_size();
```
一般很少手动用。

<hr />

#### 六、迭代器
**1. ``begin()`` / ``end()``**
作用：返回首元素、尾后迭代器
```cpp
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
}
```

<br />

**2. ``rbegin()`` / ``rend()``**
作用：反向遍历
```cpp
for (auto it = s.rbegin(); it != s.rend(); ++it) {
    cout << *it << " ";
}
```

<hr />

#### 七、其他操作
**1. ``swap(other)``**
作用：交换两个容器内容
```cpp
set<int> a = {1, 2};
set<int> b = {3, 4};
a.swap(b);
```

<br />

**2. ``erase_if(c, pred)`` C++20**
作用：按条件删除元素
```cpp
erase_if(s, [](int x) { return x % 2 == 0; });
```

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

<hr />

#### 时间复杂度
两者常见操作基本都是：

- 插入：``O(log n)``
- 删除：``O(log n)`` 或相关范围复杂度
- 查找：``O(log n)``

<hr />

### ``set``和``multiset``的常用算法模板

<hr />

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

<hr />

#### 模板2：``set``判断某数是否出现过
```cpp
#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(10);
    s.insert(20);

    if (s.count(10)) {
        cout << "存在\n";
    } else {
        cout << "不存在\n";
    }

    return 0;
}
```
也可以写：
```cpp
if(s.find(10)!=s.end())
```

<hr />

#### 模板3：``set`` 找第一个大于等于 ``x`` 的数
```cpp
set<int> s = {1, 3, 5, 7, 9};

auto it = s.lower_bound(4);
if (it != s.end()) {
    cout << *it << endl;   // 5
}
```