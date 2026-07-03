#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void dfs_basic(vector<T> &nums, vector<int> &used, vector<T> &path,
               vector<vector<T>> &res) {
  if (path.size() == nums.size()) {
    res.push_back(path);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (used[i])
      continue;
    used[i] = true;
    path.push_back(nums[i]);

    dfs_basic(nums, used, path, res);

    path.pop_back(); // 回溯
    used[i] = false; // 回溯
  }
}

template <typename T> void print(vector<vector<T>> res) {
  for (const auto &v : res) {
    for (const auto &x : v) {
      cout << x << " ";
    }
    cout << endl;
  }

  cout << "Total: " << res.size() << endl << endl;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  vector<vector<int>> res;
  vector<int> path;
  vector<int> used(nums.size(), false);

  dfs_basic(nums, used, path, res);

  return 0;
}