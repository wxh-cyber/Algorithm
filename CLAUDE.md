# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## About This Repository

A personal C++ algorithm template and competitive programming practice repository. Each `.cpp` file is self-contained with its own `main()` — there is no build system or shared project file.

## Compiling Individual Files

Each file compiles independently. Use g++ on the command line:

```bash
g++ -O2 -o output "path/to/file.cpp"
```

Or open the file in Visual Studio (`.vs/` workspace files are present).

## Repository Structure

```
动态规划/          # DP templates (01背包 one/two-dim, 完全背包, 多重背包)
数学/
  模拟与高精度/    # High-precision arithmetic (string-based big integers)
  数论/筛法/       # Number theory sieves (埃氏筛法, etc.)
输入输出/          # I/O optimization templates + performance notes (README.md)
洛谷刷题/          # Luogu OJ solutions, organized by topic (递归, 模拟, ...)
```

## Code Conventions

- All comments and variable names may be in Chinese.
- Every file begins with a block comment containing the problem link (洛谷, LeetCode, etc.) and a brief explanation of the solution approach.
- Templates use `scanf/printf` for performance-sensitive code; `cin/cout` with `ios::sync_with_stdio(false); cin.tie(0);` for moderate data sizes. See `输入输出/README.md` for the full I/O performance tier breakdown.
- More complex utility code (e.g., FFT-based polynomial class) uses a named namespace (e.g., `namespace mikiwang`).
- Arrays are typically 1-indexed (`for (int i = 1; i <= n; i++)`).

## I/O Performance Tiers (summary from 输入输出/README.md)

| Tier | Method | Use When |
|------|--------|----------|
| Slowest | `cin/cout` (default) | N < 10^4 |
| Medium | `cin/cout` + sync disabled | N ≈ 10^5–10^6 |
| Fast | `scanf/printf` | formatted input, large N |
| Faster | `getchar/putchar` fast-read | N ≈ 10^6–10^7 |
| Fastest | `fread/fwrite` | N > 10^7, extreme time limits |

Templates for the two fast-read approaches are in `输入输出/`.

## External References

- [洛谷](https://www.luogu.com.cn)
- [CodeForces](https://codeforces.com)
- [LeetCode](https://leetcode.cn)
- [牛客](https://ac.nowcoder.com)
- [OI Wiki](https://oi-wiki.org/)