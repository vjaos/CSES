#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;

bool k_sum(const std::vector<std::pair<ll, int>> &a, int k, int i, ll trg) {
  int n = static_cast<int>(a.size());
  if (k == 2) {
    int l = i;
    int r = n - 1;

    while (l < r) {
      ll sum = a[l].first + a[r].first;
      if (sum == trg) {
        std::cout << a[l].second << " " << a[r].second << " ";
        return true;
      } else if (sum < trg)
        l++;
      else
        r--;
    }
  } else {
    for (int j = i; j <= n - k; ++j) {
      ll new_trg = trg - a[j].first;
      if (k_sum(a, k - 1, j + 1, new_trg)) {
        std::cout << a[j].second << " ";
        return true;
      }
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  ll x;
  std::cin >> n >> x;
  std::vector<std::pair<ll, int>> a(n);

  for (int i = 0; i != n; ++i) {
    std::cin >> a[i].first;
    a[i].second = i + 1;
  }

  sort(a.begin(), a.end());

  bool found = k_sum(a, 4, 0, x);

  if (!found)
    std::cout << "IMPOSSIBLE" << std::endl;

  return 0;
}