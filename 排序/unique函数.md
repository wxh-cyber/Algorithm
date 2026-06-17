# ``unique``函数

<hr />

在 C++ 中，``std::unique`` 是 ``<algorithm>`` 头文件提供的一个非常常用的泛型算法。它的主要作用是：**移除序列中相邻的重复元素，并把不重复的元素移到容器的前面**。

<br />

## 1.如何工作

``std::unique`` 有一个很重要的特性：**它不会真正改变容器的实际大小**。

- 它会遍历容器，把不重复的元素依次挪到前面。
- 处理完成后，它会返回一个**迭代器**，指向新逻辑末尾的下一个位置。
- 在这个迭代器之后的元素，依然存在于容器中，但它们是“废弃的”或“未定义的”垃圾元素。

因此，在实际开发中，``std::unique`` 几乎总是和容器的 ``erase()`` 方法配合使用，以真正删除多余的元素。这被称为 **Erase-Unique 惯用法**。

<br />

## 2.前提条件

``std::unique`` 只能移除相邻的重复元素。如果原本的序列是无序的，比如 ``{1, 2, 1}``，它不会把第二个 ``1`` 当作重复元素移除。

因此，使用 ``std::unique`` 之前，通常需要先对容器进行排序（如 ``std::sort``）。

<br />

## 3.标准用法示例

**去重**
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec={1,2,2,3,1,1,4};

    // 第一步：排序（保证重复元素相邻）
    sort(vec.begin(),vec.end());
    // 此时vec中的内容是：1,1,1,2,2,3,4

    // 第二步：使用unique去重，获取新逻辑末尾迭代器
    auto last=unique(vec.begin(),vec.end());
    // 此时vec中的内容是：1,2,3,4,?,?,?
    // 前四个是有效的，后面是垃圾数据，last 指向第一个 '?'（即第二个位置）
    
     // 第三步：使用 erase 真正删除末尾的废弃元素
    vec.erase(last, vec.end());

    // 打印结果
    for (int i : vec) {
        std::cout << i << " "; 
    }
    // 输出: 1 2 3 4

    return 0;
}
```

<br />

## 4.进阶用法：自定义去重规则

``std::unique`` 还可以接受第四个参数，一个二元谓词（比较函数或 Lambda 表达式），用于定义什么是“重复”。

例如，我们想对一个字符串数组去重，但要求**不区分大小写**：
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main(){
    vector<std::string> words = {"Apple", "apple", "Banana", "banana", "Cherry"};

    auto cmp = [](const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        for (size_t i = 0; i < a.size(); ++i) {
            if (tolower(a[i]) != tolower(b[i])) return false;
        }
        return true; // 只要忽略大小写后相等，就认为是重复的
    };

    auto last = unique(words.begin(), words.end(), cmp);
    words.erase(last, words.end());

    for (const auto& w : words) {
        std::cout << w << " ";
    }
    // 输出可能是: Apple Banana Cherry

    return 0;
}
```
