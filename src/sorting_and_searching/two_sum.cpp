#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  int n;
  long long x;

  typedef std::pair<long long, int> val_with_pos;

  std::cin >> n >> x;
  std::vector<val_with_pos> a(n);

  long long v;
  for (int i = 0; i < n; i++) {
    std::cin >> v;
    a[i] = std::make_pair(v, i + 1);
  }

  auto cmp = [](val_with_pos a, val_with_pos b) {
    return a.first < b.first;
  };

  std::sort(a.begin(), a.end(), cmp);

  int i = 0;
  int j = n - 1;

  while (i < j) {
    long long sum = a[i].first + a[j].first;
    if (sum == x) {
      std::cout << a[i].second << " " << a[j].second << std::endl;
      return 0;
    } else if (sum < x)
      i++;
    else
      j--;
  }

  std::cout << "IMPOSSIBLE" << std::endl;
  return 0;
}