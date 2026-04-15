## 前缀和差分

### 前缀和中用到的相关函数

C++ 标准库中实现了前缀和函数 **std::partial_sum**，定义于头文件 `<numeric>` 中．从 C++17 开始，标准库还提供了一个功能相同的前缀和函数 **std::inclusive_scan**，同样定义于头文件 `<numeric>` 中．

**partial_sum**

- 作用：计算数组的前缀和
- 语法：partial_sum(数组.begin(),数组.end(),前缀和数组.begin(),二元运算符())
- 注意：

1. 前缀和数组的大小必须大于等于原数组的大小
2. 二元运算符可以是加法、乘法等，默认是加法运算符。

```cpp
  //plus<int>() —— 前缀和（默认行为）

  vector<int> a = {1, 2, 3, 4, 5};
  partial_sum(a.begin(), a.end(), result.begin(), plus<int>());
  // 计算过程：
  // result[0] = 1
  // result[1] = 1 + 2 = 3
  // result[2] = 3 + 3 = 6
  // result[3] = 6 + 4 = 10
  // result[4] = 10 + 5 = 15
```

```cpp
  multiplies<int>() —— 前缀积

  partial_sum(a.begin(), a.end(), result.begin(), multiplies<int>());
  // 计算过程：
  // result[0] = 1
  // result[1] = 1 * 2 = 2
  // result[2] = 2 * 3 = 6
  // result[3] = 6 * 4 = 24
  // result[4] = 24 * 5 = 120
```

3. 本质：第四个参数 op 改变的是每一步的运算规则：

```cpp
result[i]=op(result[i-1],a[i]);
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;也可以传入自定义 lambda:

```cpp
//前缀最大值
partial_sum(a.begin(),a.end(),result.begin(),[](int a,int b){return max(a,b);});
```

4. 常用的内置函数对象，如`plus<T>`,`multiplies<T>`,`minus<T>`,`divides<T>`,`modulus<T>`等，这些都定义在`<functional>`头文件中。

- 示例：

```cpp
partial_sum(a.begin(),a.end(),ps.begin(),plus<int>());
```

```cpp
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    vector<int> a={1,2,3,4,5};
    vector<int> ps(a.size());
    vector<int> mul(a.size());

    partial_sum(a.begin(),a.end(),ps.begin());
    //ps={1,3,6,10,15}

    for(int i=0;i<ps.size();i++){
        cout<<ps[i]<<endl;
    }

    //也可以自定义运算，比如前缀积
    partial_sum(a.begin(),a.end(),mul.begin(),multiplies<int>());
    //mul={1,2,6,24,120}

    for(int i=0;i<mul.size();i++){
        cout<<mul[i]<<endl;
    }

    return 0;
}
```

**inclusive_scan**

- 作用：计算数组的前缀和，与 partial_sum 类似。但不同的是，支持并行执行策略，适合多核加速。
- 语法：inclusive_scan(数组.begin(),数组.end(),前缀和数组.begin())
- 注意：前缀和数组的大小必须大于等于原数组的大小
- 示例：

```cpp
//串行
inclusive_scan(a.begin(),a.end(),ps.begin());

//并行（需要编辑器支持）
inclusive_scan(execution::par,a.begin(),a.end(),ps.begin());
```

```cpp
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    vector<int> a={1,2,3,4,5};
    vector<int> ps(a.size());

    inclusive_scan(a.begin(),a.end(),ps.begin());
    //ps={1,3,6,10,15}

    for(int i=0;i<ps.size();i++){
        cout<<ps[i]<<endl;
    }

    return 0;
}

```

**竞赛中的常见用法**<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在算法竞赛中，手写前缀和更常见，但 partial_sum 可以简化代码：

```cpp
vector<int> a={1,2,3,4,5};
//原地前缀和
partial_sum(a.begin(),a.end(),a.begin());
//a={1,3,6,10,15}

//查询区间
int sum=a[r]-(l>0?a[l-1]:0);
```
