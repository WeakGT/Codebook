#include <bits/stdc++.h>

std::bitset<1000> a[500];

int main() {
  int n; std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0, t; j < n; ++j)
      std::cin >> t, a[i][j] = t;
    a[i][i + n] = 1;
  }
  for (int i = 0; i < n; ++i) {
    int t;
    for (t = i; t < n; ++t) if (a[t][i]) break;
    if (t == n) return std::cout << "-1\n", 0;
    std::swap(a[i], a[t]);
    for (int j = i + 1; j < n; ++j) if (a[j][i]) a[j] ^= a[i];
  }
  for (int i = n - 1; i >= 0; --i)
    for (int j = i - 1; j >= 0; --j)
      if (a[j][i]) a[j] ^= a[i];
  for (int i = 0; i < n; ++i) {
    std::vector<int> ans;
    for (int j = n; j < 2 * n; ++j) if (a[i][j]) ans.push_back(j - n + 1);
    for (size_t j = 0; j < ans.size(); ++j)
      std::cout << ans[j] << " \n"[j == ans.size()];
  }
  return 0;
}