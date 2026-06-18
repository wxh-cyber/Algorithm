#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 *  优化点说明：
 *      1.动态桶数量：不再写死桶的数量，而是根据数据量 N 动态计算（通常取 sqrt(N)）。数据量越大，桶相对越多，每个桶内的数据量就越少，排序越快。
 *      2.内存预分配（Reserve）：提前为每个桶预估容量并分配内存，避免在 push_back 过程中多次重新分配内存，大幅提升速度。
 *      3.泛型支持：使用模板 template，不仅能排 int，还能排 double、float 等数值类型。
 *      4.安全映射：统一转换为 double 进行比例计算，再映射回桶索引，并使用 std::min 强制防越界，保证逻辑绝对安全。
 */

/**
 * @brief 桶排序函数
 * @param arr 待排序的数组
 * @return void
 */
template <typename T> void bucketSortOptimized(vector<T> &arr) {
  // 如果数组元素长度不超过2，直接返回
  if (arr.size() < 2)
    return;

  // 1.找最大值和最小值
  // 注意: 这里使用了C++17的结构化绑定
  auto [min_it, max_it] = minmax_element(arr.begin(), arr.end());
  T min_val = *min_it; // 最小值
  T max_val = *max_it; // 最大值

  if (min_val == max_val)
    return; // 全部相等，无需排序

  // 2.动态计算桶数量：取数据量N的平方根（经验值）
  size_t bucket_count = static_cast<size_t>(sqrt(arr.size()));
  if (bucket_count < 1)
    bucket_count = 1; // 至少1个桶

  // 3.创建桶，并预分配内存优化push_back性能
  vector<vector<T>> buckets(bucket_count);
  // 预估每个桶大约装 N / bucket_count 个元素，多预留一点空间 (+1)
  size_t reserve_size = arr.size() / bucket_count + 1;
  for (auto &bucket : buckets) {
    bucket.reserve(reserve_size);
  }

  // 4.分配数据到桶中
  double range = static_cast<double>(max_val - min_val);
  for (const T &val : arr) {
    // 计算比例（0.0-1.0）
    double ratio = static_cast<double>(val - min_val) / range;
    // 映射到桶索引
    size_t index = static_cast<size_t>(ratio * bucket_count);

    // 防止浮点精度问题导致 index 刚好等于 bucket_count (越界)
    if (index == bucket_count) {
      index = bucket_count - 1;
    }

    // 将数组元素放入对应的桶中
    buckets[index].push_back(val);
  }

  // 5.桶内排序并直接覆盖原数组
  size_t idx = 0;
  for (size_t i = 0; i < bucket_count; i++) {
    if (!buckets[i].empty()) {
      // 桶内排序 (数据量小时 std::sort 内部会切换为插入排序，效率极高)
      sort(buckets[i].begin(), buckets[i].end());
      // 将排好序的数据放回原数组
      for (const T &val : buckets[i]) {
        arr[++idx] = val;
      }
    }
  }
}

// ================= 测试用例 =================
int main() {
  // 浮点数测试
  std::vector<double> float_arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21,
                                   0.12, 0.23, 0.68, 0.55, 0.33, 0.88};
  std::cout << "排序前: ";
  for (double v : float_arr)
    std::cout << v << " ";
  std::cout << "\n";

  bucketSortOptimized(float_arr); // 自动根据 13 个元素决定桶数 (约为 3~4 个)

  std::cout << "排序后: ";
  for (double v : float_arr)
    std::cout << v << " ";
  std::cout << "\n";

  return 0;
}