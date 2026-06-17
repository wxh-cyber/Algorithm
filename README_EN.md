# Algorithm

This repository records algorithm-related content, mainly algorithm templates and problem-solving notes.

Probably really powered by pure enthusiasm (doge), and ready to be outclassed by elementary school students...

Continuously updated...

![中文](./README.md)|English

![C++](https://img.shields.io/badge/C++-red?style=for-the-badge&logo=cplusplus&logoColor=blue)
![C](https://img.shields.io/badge/C-purple?style=for-the-badge&logo=c&logoColor=skyblue)
![Luogu](https://img.shields.io/badge/Luogu-white?style=for-the-badge&logo=Luogu&logoColor=5b9bd5)
![CodeForces](https://img.shields.io/badge/CodeForces-yellow?style=for-the-badge&logo=Codeforces&logoColor=red)
![LeetCode](https://img.shields.io/badge/LeetCode-black?style=for-the-badge&logo=LeetCode&logoColor=ffa116)
![Claude](https://img.shields.io/badge/Claude-f0eee6?style=for-the-badge&logo=Claude&logoColor=d97757)
![](./assets/image.png)

## Contents

### I. Basic Knowledge

**Notes**:
- Basic knowledge mainly covers type conversion, input/output, and basic STL. More detailed material is included in the dedicated knowledge sections inside the templates.
- For each standalone knowledge section, it is recommended to read the corresponding Markdown file first and then study the code alongside it.

- [Type Conversion](./基础知识/类型转换.md)
- [Input/Output](./基础知识/输入输出//输入输出)
  - [Input and Output Streams](./基础知识//输入输出/输入输出流.md)
  - [String Versions of `scanf` and `printf`](./基础知识/输入输出/字符串版本的scanf和printf.md)
  - [Other Input/Output Methods](./基础知识/输入输出//其他输入输出.md)
- [STL](./基础知识/STL/)
  - [`set` and `multiset`](./基础知识/STL/set和multiset.md.md)

### II. Algorithm Templates

- [Input/Output](./输入输出/)
  - [Fast Input/Output (Basic)](./输入输出/快读快写（基础版）.cpp)
  - [Fast Input/Output (Extreme)](./输入输出/快读快写（极限版）.cpp)
  - [Input/Output Performance Comparison](./输入输出/README.md)
- [Sorting](./排序/)
  - [Quick Sort](./排序/快速排序/)
    - [Basic Template](./排序/快速排序/基础模板.cpp)
    - [Optimized Template](./排序/快速排序/优化模板.cpp)
    - [Algorithm Analysis](./排序/快速排序/算法分析.md)
  - [Bucket Sort](./排序/桶排序/)
    - [Basic Template](./排序/桶排序/基础模板.cpp)
    - [Optimized Template](./排序/桶排序/优化模板.cpp)
    - [Algorithm Analysis](./排序/桶排序/算法分析.md)
  - [How `sort` Works Internally](./排序/sort的底层实现.md)
  - [`nth_element` Function](./排序/nth_element函数.md)
  - [`unique` Function](./排序/unique函数.md)
- [Dynamic Programming](./动态规划/)
  - [0/1 Knapsack (2D)](./动态规划/01背包模板（二维）.cpp)
  - [0/1 Knapsack (1D)](./动态规划/01背包模板（一维）.cpp)
  - [Complete Knapsack](./动态规划/完全背包模板.cpp)
  - [Multiple Knapsack](./动态规划/多重背包模板.cpp)
  - [Optimized Multiple Knapsack (Binary Optimization)](./动态规划/多重背包优化模板.cpp)
- [Mathematics](./数学/)
  - [Simulation and High Precision](./数学/模拟与高精度/)
    - [High-Precision Addition](./数学/模拟与高精度/高精度加法/)
      - [High-Precision Addition](./数学/模拟与高精度/高精度加法/高精度加法.cpp)
      - [High-Precision Addition with Digit Compression](./数学/模拟与高精度/高精度加法/高精度加法压位.cpp)
    - [High-Precision Subtraction](./数学/模拟与高精度/高精度减法)
      - [High-Precision Subtraction](./数学/模拟与高精度/高精度减法/高精度减法.cpp)
      - [High-Precision Subtraction with Digit Compression](./数学/模拟与高精度/高精度减法/高精度减法压位.cpp)
    - [High-Precision Multiplication](./数学/模拟与高精度/高精度乘法)
      - [High-Precision Multiplication](./数学/模拟与高精度/高精度乘法/高精度乘法.cpp)
      - [High-Precision Multiplication with Dimensionality Reduction and Digit Compression](./数学/模拟与高精度/高精度乘法/高精度乘法降维压位.cpp)
    - [High-Precision Division](./数学/模拟与高精度/高精度除法/)
      - [High Precision Divided by Low Precision](./数学/模拟与高精度/高精度除法/高精度除以低精度.cpp)
      - [High Precision Divided by High Precision (Basic)](./数学/模拟与高精度/高精度除法/高精度除以高精度（基础版）.cpp)
      - [High Precision Divided by High Precision (Optimized)](./数学/模拟与高精度/高精度除法/高精度除以高精度（优化版）.cpp)
    - [Digit Compression in High-Precision Arithmetic](./数学/模拟与高精度/高精度运算中的压位.md)
  - [Number Theory](./数学/数论/)
    - [Sieve of Eratosthenes](./数学/数论/筛法/埃氏筛法.cpp)
- [Prefix Sum and Difference](./前缀和差分/)
  - [Overview of Prefix Sums and Differences](./前缀和差分/README.md)
  - [1D Prefix Sum](./前缀和差分/一维前缀和.cpp)
  - [2D Prefix Sum](./前缀和差分/二维前缀和.cpp)

### III. Problem-Solving Records

**Categorization Note**: In practice, a single algorithm problem may involve multiple techniques. This directory is only one way of classifying them, so please analyze each problem based on its actual requirements.

- [Luogu Problem-Solving](./洛谷刷题/)
  - [Recursion](./洛谷刷题/递归/)
    - [Moonset, Crows, and Counting Money (P1720)](./洛谷刷题/递归/月落乌啼算钱/)
    - [Pardoning Prisoners of War (P5461)](./洛谷刷题/递归/赦免战俘/)
  - [Simulation](./洛谷刷题/模拟/)
    - [Longest Consecutive Sequence (P1420)](./洛谷刷题/模拟/最长连号/)
    - [Printing Triangles (P5725)](./洛谷刷题/模拟/求三角形/)
    - [Mental Arithmetic Beads (P2141)](./洛谷刷题/模拟/珠心算/)
    - [Compression Technique (P1319)](./洛谷刷题/模拟/压缩技术/)
    - [Transformations (P1205)](./洛谷刷题/模拟/方块转换.cpp)
    - [Arithmetic Exercise (P1957)](./洛谷刷题/模拟/口算练习题/)
    - [Two Cows (P1518)](./洛谷刷题/模拟/两只牛/)
    - [String Expansion (P1098)](./洛谷刷题/模拟/字符串的展开/)
    - [Job Scheduling Scheme (P1065)](./洛谷刷题/模拟/作业调度方案.cpp)
  - [High Precision](./洛谷刷题/高精度/)
    - [Sum of Factorials (P1009)](./洛谷刷题/高精度/阶乘之和/)
    - [Mersenne Number (P1045)](./洛谷刷题/高精度/麦森数)
    - [Counting Stairs (P1255)](./洛谷刷题/高精度/数楼梯/)
  - [Strings](./洛谷刷题/字符串/)
    - [Counting Words (P1308)](./洛谷刷题/字符串/统计单词数/)
    - [Xiaoguo's Keyboard (P3741)](./洛谷刷题/字符串/小果的键盘.cpp)
    - [Mobile Phone (P1765)](./洛谷刷题/字符串/手机/)
    - [Number Reversal, Upgraded (P1553)](./洛谷刷题/字符串/数字反转·升级版/)
  - [Sorting](./洛谷刷题/排序/)
    - [Gang Contribution Sorting (P1786)](./洛谷刷题/排序/帮贡排序/)
    - [Sorting (P1177)](./洛谷刷题/排序/排序/)
  - [Greedy](./洛谷刷题/贪心/)
    - [Maximum Product (P1249)](./洛谷刷题/贪心/最大乘积/)
  - [Mathematics](./洛谷刷题/数学/)
    - [Sieve Methods](./洛谷刷题/数学/筛法/)
      - [Prime Sieve (P5736)](./洛谷刷题/数学/筛法/质数筛/)
      - [Goldbach's Conjecture (P1304)](./洛谷刷题/数学/筛法/哥德巴赫猜想/)
    - [Permutations and Combinations](./洛谷刷题/数学/排列组合/)
      - [Set Summation (P2415)](./洛谷刷题/数学/排列组合/集合求和/)

> Note: The Basic Knowledge section is mainly supplemented from parts of OI Wiki. For broader coverage, please refer to OI Wiki.

## Usage

- It is recommended to open this repository in Visual Studio, then select the `Algorithm` folder in the left sidebar to browse the content.
- It is not recommended to run the code directly in VS Code, because setting up the environment is relatively troublesome.
- You can directly copy a template into the corresponding problem and then compile and run it.

## External Links

- ![Luogu](https://img.shields.io/badge/Luogu-white?style=for-the-badge&logo=Luogu&logoColor=5b9bd5)[Luogu](https://www.luogu.com.cn)
- ![CodeForces](https://img.shields.io/badge/CodeForces-yellow?style=for-the-badge&logo=Codeforces&logoColor=red)[CodeForces](https://codeforces.com)
- ![LeetCode](https://img.shields.io/badge/LeetCode-black?style=for-the-badge&logo=LeetCode&logoColor=ffa116)[LeetCode](https://leetcode.cn)
- [Nowcoder](https://ac.nowcoder.com)
- [OI Wiki](https://oi-wiki.org/)
- [POJ](poj.org)
