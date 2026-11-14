# Algorithm

This repository collects algorithm-related materials, mainly algorithm templates and competitive-programming solution records.

This may really be powered by pure enthusiasm (doge), while getting ready to be outclassed by an elementary-school student...

The repository is continuously updated.

Algorithm templates and their comments are updated first, followed by solution explanations. Updates may be slow during graduate-school entrance-exam preparation.

[中文](./README.md) | **English**

![C++](https://img.shields.io/badge/C++-red?style=for-the-badge&logo=cplusplus&logoColor=blue)
![C](https://img.shields.io/badge/C-purple?style=for-the-badge&logo=c&logoColor=skyblue)
![Luogu](https://img.shields.io/badge/Luogu-white?style=for-the-badge&logo=Luogu&logoColor=5b9bd5)
![Codeforces](https://img.shields.io/badge/CodeForces-yellow?style=for-the-badge&logo=Codeforces&logoColor=red)
![LeetCode](https://img.shields.io/badge/LeetCode-black?style=for-the-badge&logo=LeetCode&logoColor=ffa116)
![Claude](https://img.shields.io/badge/Claude-f0eee6?style=for-the-badge&logo=Claude&logoColor=d97757)
![](./assets/image.png)

## My accounts

![Luogu](https://www.luogu.com.cn/user/933148)

## Contents

### 1. Basic knowledge

**Notes**:
- Basic knowledge mainly covers type conversions, input/output, and fundamental STL containers. More specific topics are documented separately alongside the templates.
- For each topic, read the corresponding Markdown document first, then refer to the code for a deeper understanding.

<br />

- [Types](./基础知识/类型)
  - [Type conversions](./基础知识/类型/类型转换.md)
  - [size_t](./基础知识/类型/size_t.md)
- [Input and output](./基础知识/输入输出//输入输出)
    - [Input/output streams](./基础知识//输入输出/输入输出流.md)
    - [String versions of scanf and printf](./基础知识/输入输出/字符串版本的scanf和printf.md)
    - [Other input and output](./基础知识/输入输出//其他输入输出.md)
- [memset function](./基础知识/memset函数.md)
- [STL](./基础知识/STL/)
    - [set and multiset](./基础知识/STL/set和multiset.md.md)
    - [list](./基础知识/STL/list.md)
    - [deque and queue](./基础知识/STL/deque和queue.md)

### 2. Algorithm templates

- [Input and output](./输入输出/)
  - [Fast input and output (basic version)](./输入输出/快读快写（基础版）.cpp)
  - [Fast input and output (extreme version)](./输入输出/快读快写（极限版）.cpp)
  - [Input/output performance comparison](./输入输出/README.md)
- [Sorting](./排序/)
  - [Insertion sort](./排序/插入排序/)
    - [Basic template](./排序/插入排序/基础模板.cpp)
    - [Optimized template](./排序/插入排序/优化模板.cpp)
  - [Quick sort](./排序/快速排序/)
    - [Basic template](./排序/快速排序/基础模板.cpp)
    - [Optimized template](./排序/快速排序/优化模板.cpp)
    - [Algorithm analysis](./排序/快速排序/算法分析.md)
  - [Selection sort](./排序/选择排序/)
    - [Basic template](./排序/选择排序/基础模板.cpp)
    - [Optimized template](./排序/选择排序/优化模板.cpp)
  - [Bubble sort](./排序/冒泡排序/)
    - [Basic template](./排序/冒泡排序/基础模板.cpp)
    - [Optimized template](./排序/冒泡排序/优化模板.cpp)
  - [Merge sort](./排序/归并排序/)
    - [Basic template](./排序/归并排序/基础模板.cpp)
    - [Optimized template](./排序/归并排序/优化模板.cpp)
    - [Algorithm analysis](./排序/归并排序/算法分析.md)
  - [Shell sort](./排序/希尔排序/)
    - [Basic template](./排序/希尔排序/基础模板.cpp)
    - [Optimized template](./排序/希尔排序/优化模板.cpp)
    - [Algorithm analysis](./排序/希尔排序/算法分析.md)
  - [Heap sort](./排序/堆排序/)
    - [Basic template](./排序/堆排序/基础模板.cpp)
    - [Optimized template](./排序/堆排序/优化模板.cpp)
  - [Bucket sort](./排序/桶排序/)
    - [Basic template](./排序/桶排序/基础模板.cpp)
    - [Optimized template](./排序/桶排序/优化模板.cpp)
    - [Algorithm analysis](./排序/桶排序/算法分析.md)
  - [How sort is implemented](./排序/sort的底层实现.md)
  - [iter_swap function](./排序/iter_swap函数.md)
  - [distance function](./排序/distance函数.md)
  - [nth_element function](./排序/nth_element函数.md)
  - [lower_bound function](./排序/lower_bound函数.md)
  - [unique function](./排序/unique函数.md)
  - [move function](./排序/move函数.md)
  - [next_permutation function](./排序/next_permutation函数.md)
- [Recursion](./递归/)
  - [Properties of Pascal's triangle](./递归/杨辉三角的性质.md)
  - [Properties of the Fibonacci sequence](./递归/斐波那契数列的性质.md)
- [Dynamic programming](./动态规划/)
  - [0/1 knapsack (two-dimensional)](./动态规划/01背包模板（二维）.cpp)
  - [0/1 knapsack (one-dimensional)](./动态规划/01背包模板（一维）.cpp)
  - [Complete knapsack](./动态规划/完全背包模板.cpp)
  - [Multiple knapsack](./动态规划/多重背包模板.cpp)
  - [Optimized multiple knapsack (binary decomposition)](./动态规划/多重背包优化模板.cpp)
- [Mathematics](./数学/)
  - [Simulation and high-precision arithmetic](./数学/模拟与高精度/)
    - [High-precision addition](./数学/模拟与高精度/高精度加法/)
      - [High-precision addition](./数学/模拟与高精度/高精度加法/高精度加法.cpp)
      - [High-precision addition with digit grouping](./数学/模拟与高精度/高精度加法/高精度加法压位.cpp)
    - [High-precision subtraction](./数学/模拟与高精度/高精度减法)
      - [High-precision subtraction](./数学/模拟与高精度/高精度减法/高精度减法.cpp)
      - [High-precision subtraction with digit grouping](./数学/模拟与高精度/高精度减法/高精度减法压位.cpp)
    - [High-precision multiplication](./数学/模拟与高精度/高精度乘法)
      - [High-precision multiplication](./数学/模拟与高精度/高精度乘法/高精度乘法.cpp)
      - [Reduced-dimension high-precision multiplication with digit grouping](./数学/模拟与高精度/高精度乘法/高精度乘法降维压位.cpp)
    - [High-precision division](./数学/模拟与高精度/高精度除法/)
      - [High-precision division by a low-precision integer](./数学/模拟与高精度/高精度除法/高精度除以低精度.cpp)
      - [High-precision division by a high-precision integer (basic version)](./数学/模拟与高精度/高精度除法/高精度除以高精度（基础版）.cpp)
      - [High-precision division by a high-precision integer (optimized version)](./数学/模拟与高精度/高精度除法/高精度除以高精度（优化版）.cpp)
    - [Digit grouping in high-precision arithmetic](./数学/模拟与高精度/高精度运算中的压位.md)
  - [Number theory](./数学/数论/)
    - [Sieve of Eratosthenes](./数学/数论/筛法/埃氏筛法.cpp)
  - [Combinatorics](./数学/排列组合/)
    - [Permutations](./数学/排列组合/排列)
      - [STL template](./数学/排列组合/排列/STL模板.cpp)
      - [Depth-first search (distinct elements)](./数学/排列组合/排列/深度搜索（无重复元素）.cpp)
      - [Depth-first search (duplicate elements)](./数学/排列组合/排列/深度搜索（重复元素）.cpp)
    - [Combinations](./数学/排列组合/组合/)
      - [Basic template](./数学/排列组合/组合/基础模板.cpp)
    - [Catalan numbers](./数学/排列组合/卡特兰数.md)
    - [Cantor expansion](./数学/排列组合/康托展开.md)
- [Prefix sums and differences](./前缀和差分/)
  - [Overview of prefix sums and differences](./前缀和差分/README.md)
  - [One-dimensional prefix sums](./前缀和差分/一维前缀和.cpp)
  - [Two-dimensional prefix sums](./前缀和差分/二维前缀和.cpp)
- [Searching](./查找/)
  - [Binary search](./查找/二分查找/)
    - [Basic binary search](./查找/二分查找/基础版.cpp)
    - [Find the left boundary](./查找/二分查找/查找左边界.cpp)
    - [Find the right boundary](./查找/二分查找/查找右边界.cpp)
    - [Count occurrences of a value](./查找/二分查找/统计值出现的次数.cpp)
    - [Floating-point binary search](./查找/二分查找/浮点数二分查找.cpp)
- [Search](./搜索/)
- [Linear structures](./线性结构/)
  - [Monotonic queue](./线性结构/单调队列/)
    - [Sliding window](./线性结构/单调队列/滑动窗口.cpp)
  - [Linked list](./线性结构/链表/)
  - [Orthogonal list](./线性结构/十字链表/)
    - [Orthogonal-list storage for sparse matrices](./线性结构/链表/稀疏矩阵的十字链表存储.cpp)
    - [Matrix row swapping with an orthogonal list](./线性结构/十字链表/十字链表实现矩阵行交换.cpp)
    - [Dancing Links (DLX)](./线性结构/十字链表/舞蹈链DLX.cpp)
- [Trees](./树/)
  - [Tree traversals](./树/树的遍历/)
    - [Preorder traversal](./树/树的遍历/先序遍历/)
      - [Basic preorder traversal](./树/树的遍历/先序遍历/基本款.cpp)
      - [Iterative preorder traversal](./树/树的遍历/先序遍历/迭代款.cpp)
    - [Inorder traversal](./树/树的遍历/中序遍历/)
      - [Basic inorder traversal](./树/树的遍历/中序遍历/基本款.cpp)
      - [Iterative inorder traversal](./树/树的遍历/中序遍历/迭代款.cpp)
    - [Postorder traversal](./树/树的遍历/后序遍历/)
      - [Basic postorder traversal](./树/树的遍历/后序遍历/基本款.cpp)
      - [Postorder traversal with a useful technique](./树/树的遍历/后序遍历/技巧法.cpp)
      - [Standard postorder traversal](./树/树的遍历/后序遍历/标准法.cpp)
    - [Level-order traversal](./树/树的遍历/层次遍历/)
      - [Basic level-order traversal](./树/树的遍历/层次遍历/基础版.cpp)
- [Graphs](./图/)
  - [Graph representations](./图/存图/)
    - [Adjacency matrix](./图/存图/邻接矩阵.cpp)
    - [Vector adjacency list](./图/存图/vector邻接表.cpp)
    - [Forward-star adjacency list](./图/存图/链式前向星.cpp)
    - [Pointer-based linked-list representation](./图/存图/链表（指针版）存图.cpp)
  - [Search](./图/搜索/)
    - [DFS](./图/搜索/DFS/)
    - [BFS](./图/搜索/BFS/)
      - [BFS shortest path](./图/搜索/BFS/BFS最短路径.cpp)
      - [BFS connected-component counting](./图/搜索/BFS/BFS统计连通分量.cpp)
      - [0-1 BFS shortest path](./图/搜索/BFS/0-1%20BFS最短路径.cpp)

> Note: The basic-knowledge section supplements selected parts of OI Wiki. For more information, see OI Wiki.

### 3. Problem-solving records

**Classification note**: An algorithm problem may involve multiple techniques. The categories here are only one way to organize the solutions; analyze each problem according to its actual requirements.

- [Luogu problem solutions](./洛谷刷题/)
  - [Recursion](./洛谷刷题/递归/)
    - [Money Calculation (P1720)](./洛谷刷题/递归/月落乌啼算钱/)
    - [Prisoner Amnesty (P5461)](./洛谷刷题/递归/赦免战俘/)
    - [Solving a cubic equation (P1024)](./洛谷刷题/递归/一元三次方程求解/)
    - [Stack (P1044)](./洛谷刷题/递归/栈/)
    - [Alien code (P1928)](./洛谷刷题/递归/外星密码/)
    - [Covering a wall (P1990)](./洛谷刷题/递归/覆盖墙壁/)
    - [Carpet tiling (P1228)](./洛谷刷题/递归/地毯填补问题/)
    - [Southern barbarian totem (P1498)](./洛谷刷题/递归/南蛮图腾/)
  - [Simulation](./洛谷刷题/模拟/)
    - [Longest consecutive sequence (P1420)](./洛谷刷题/模拟/最长连号/)
    - [Constructing a triangle (P5725)](./洛谷刷题/模拟/求三角形/)
    - [Mental arithmetic (P2141)](./洛谷刷题/模拟/珠心算/)
    - [Compression technology (P1319)](./洛谷刷题/模拟/压缩技术/)
    - [Block transformation (P1205)](./洛谷刷题/模拟/方块转换.cpp)
    - [Mental calculation exercises (P1957)](./洛谷刷题/模拟/口算练习题/)
    - [Two cows (P1518)](./洛谷刷题/模拟/两只牛/)
    - [String expansion (P1098)](./洛谷刷题/模拟/字符串的展开/)
    - [Job-shop scheduling (P1065)](./洛谷刷题/模拟/作业调度方案.cpp)
  - [High-precision arithmetic](./洛谷刷题/高精度/)
    - [Sum of factorials (P1009)](./洛谷刷题/高精度/阶乘之和/)
    - [Mason number (P1045)](./洛谷刷题/高精度/麦森数)
    - [Staircase counting (P1255)](./洛谷刷题/高精度/数楼梯/)
  - [Enumeration](./洛谷刷题/枚举/)
    - [Triple hit (P1008)](./洛谷刷题/枚举/三连击/)
    - [Triple hit, upgraded (P1618)](./洛谷刷题/枚举/三连击（升级版）/)
    - [Cantor's table (P1014)](./洛谷刷题/枚举/Cantor表/)
    - [Missile interception (P1158)](./洛谷刷题/枚举/导弹拦截/)
  - [Strings](./洛谷刷题/字符串/)
    - [Word count (P1308)](./洛谷刷题/字符串/统计单词数/)
    - [Xiaoguo's keyboard (P3741)](./洛谷刷题/字符串/小果的键盘.cpp)
    - [Mobile phone (P1765)](./洛谷刷题/字符串/手机/)
    - [Number reversal, upgraded (P1553)](./洛谷刷题/字符串/数字反转·升级版/)
  - [Sorting](./洛谷刷题/排序/)
    - [Merit-based sorting (P1786)](./洛谷刷题/排序/帮贡排序/)
    - [Sorting (P1177)](./洛谷刷题/排序/排序/)
    - [Carriage rearrangement (P1116)](./洛谷刷题/排序/车厢重组/)
    - [College-entrance-exam preference (P1678)](./洛谷刷题/排序/烦恼的高考志愿/)
    - [Concatenated numbers (P1012)](./洛谷刷题/排序/拼数/)
  - [Greedy algorithms](./洛谷刷题/贪心/)
    - [Maximum product (P1249)](./洛谷刷题/贪心/最大乘积/)
    - [Segment coverage (P1803)](./洛谷刷题/贪心/线段覆盖/)
    - [The king's game (P1080)](./洛谷刷题/贪心/国王游戏/)
  - [Searching](./洛谷刷题/查找/)
    - [Binary search](./洛谷刷题/查找/二分查找/)
      - [A-B number pairs (P1102)](./洛谷刷题/查找/二分查找/A-B数对/)
      - [Cutting trees (P1873)](./洛谷刷题/查找/二分查找/砍树/)
      - [Jumping stones (P2678)](./洛谷刷题/查找/二分查找/跳石头/)
      - [Sign placement (P3853)](./洛谷刷题/查找/二分查找/路标设置/)
      - [Thoughts on jumping stones and sign placement](./洛谷刷题/查找/二分查找/跳石头和路标设置的思考.md)
      - [Segmenting a sequence (P1182)](./洛谷刷题/查找/二分查找/数列分段/)
      - [Bird equipment (P3743)](./洛谷刷题/查找/二分查找/小鸟的设备/)
  - [Search](./洛谷刷题/搜索/)
    - [Knight's tour (P1443)](./洛谷刷题/搜索/马的遍历/)
    - [Meteor shower (P2895)](./洛谷刷题/搜索/流星雨/)
    - [Word chain (P1019)](./洛谷刷题/搜索/单词接龙/)
    - [Natural-number decomposition (P2404)](./洛谷刷题/搜索/自然数的拆分/)
    - [Coloring (P1162)](./洛谷刷题/搜索/填涂颜色/)
  - [Dynamic programming](./洛谷刷题/动态规划/)
    - [Cramming at the last minute (P2392)](./洛谷刷题/动态规划/临时抱佛脚/)
    - [Counting words (P1026)](./洛谷刷题/动态规划/统计单词个数/)
  - [Mathematics](./洛谷刷题/数学/)
    - [Number theory](./洛谷刷题/数学/数论/)
      - [Greatest common divisor and least common multiple (P1029)](./洛谷刷题/数学/数论/最大公因数与最小公倍数/)
    - [Sieve methods](./洛谷刷题/数学/筛法/)
      - [Prime sieve (P5736)](./洛谷刷题/数学/筛法/质数筛/)
      - [Goldbach's conjecture (P1304)](./洛谷刷题/数学/筛法/哥德巴赫猜想/)
    - [Combinatorics](./洛谷刷题/数学/排列组合/)
      - [Set sum (P2415)](./洛谷刷题/数学/排列组合/集合求和/)
      - [Permutation problem (P1706)](./洛谷刷题/数学/排列组合/全排列问题/)
      - [Output combinations (P1157)](./洛谷刷题/数学/排列组合/组合的输出.cpp)
      - [Mars person (P1088)](./洛谷刷题/数学/排列组合/火星人/)
      - [Little Y builds sticks (P3799)](./洛谷刷题/数学/排列组合/小Y拼木棒/)
  - [Linear structures](./洛谷刷题/线性结构/)
    - [Stack](./洛谷刷题/线性结构/栈/)
      - [Postfix expression (P1449)](./洛谷刷题/线性结构/栈/后缀表达式/)
    - [Linked list](./洛谷刷题/线性结构/链表/)
      - [Josephus problem (P1996)](./洛谷刷题/线性结构/链表/约瑟夫问题/)
      - [Queue arrangement (P1012)](./洛谷刷题/线性结构/链表/队列安排/)


- [Codeforces problem solutions](./CodeForces刷题/)
  - [Strings](./CodeForces刷题/字符串/)
    - [Extended spreadsheet (1B)](./CodeForces刷题/字符串/拓展电子表格/)

### 4. Collected references

While building this competitive-programming template collection, I gathered many useful materials from other authors. They are collected here for reference.

- [408 postgraduate entrance-exam computer-test templates](./它山之石，可以攻玉/考研408DS部分代码大题_机试_信竞常用及冷门模板大全.pdf)
- [Data-structure algorithm problems](./它山之石，可以攻玉/数据结构算法题.pdf)
- [Core data-structure code memorization notes](./它山之石，可以攻玉/数据结构核心代码背诵版.pdf)
- [Fan Fan's ACM templates](./它山之石，可以攻玉/繁凡的ACM模板.pdf)
- [Fan Fan's complete ACM algorithm collection](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/)
  - [Computational geometry collection](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/计算几何基础%20繁凡的《计算几何全家桶（一）》.pdf)
  - [Common two-dimensional geometry algorithms](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/二维几何常用算法合集%20繁凡的《计算几何全家桶（二）》.pdf)
  - [Complete three-dimensional geometry fundamentals](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/三维几何基础大合集%20繁凡的《计算几何全家桶（三）》.pdf)
  - [Polynomial collection](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/繁凡的《多项式全家桶》.pdf)
  - [Combinatorics collection](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/繁凡的《组合数学全家桶》.pdf)
  - [Linear algebra collection](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/繁凡的《线性代数全家桶》.pdf)
  - [Probability and expectation collection](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/繁凡的《概率与期望全家桶》.pdf)
  - [Game theory collection](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/繁凡的《博弈论全家桶》.pdf)
  - [Group theory collection](./它山之石，可以攻玉/《繁凡的ACM算法全家桶》/繁凡的%20《群论全家桶》.pdf)
- [Elementary number theory in programming contests](./它山之石，可以攻玉/《算法竞赛中的初等数论》/)

## Usage

- Open the repository in Visual Studio, then select the `Algorithm` folder in the left sidebar to browse the materials.
- Copy a suitable template into the corresponding problem, then compile and run it.

### Debugging a single C++ file

Most `.cpp` files in this repository can be compiled and run independently. In PowerShell, open a terminal at the repository root and compile the target file first:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -o ".\tmp_solution.exe" ".\relative\path\file.cpp"
```

After compilation succeeds, run the generated program:

```powershell
& ".\tmp_solution.exe"
```

If the program requires input, provide sample input at runtime. For example:

```powershell
"25 5 2 2 11 14 17 21" | & ".\tmp_solution.exe"
```

The command above pipes one line of input into the program. If no input is required, run the executable directly. The first command only compiles the program; it does not run it automatically.

To debug the currently open `.cpp` file in VS Code, press `F5`. The project’s `.vscode/launch.json` first invokes the compilation task and then starts debugging. You can also press `Ctrl+Shift+B` to compile separately, then run the generated `.exe` file in the terminal.

## External links

- ![Luogu](https://img.shields.io/badge/Luogu-white?style=for-the-badge&logo=Luogu&logoColor=5b9bd5)[Luogu](https://www.luogu.com.cn)
- ![Codeforces](https://img.shields.io/badge/CodeForces-yellow?style=for-the-badge&logo=Codeforces&logoColor=red)[Codeforces](https://codeforces.com)
- ![LeetCode](https://img.shields.io/badge/LeetCode-black?style=for-the-badge&logo=LeetCode&logoColor=ffa116)[LeetCode](https://leetcode.cn)
- [Nowcoder](https://ac.nowcoder.com)
- [OI Wiki](https://oi-wiki.org/)
- [Peking University Online Judge](poj.org)
