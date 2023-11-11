#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;

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

  std::sort(a.begin(), a.end());

  for (int i = 0; i != n; ++i) {
    ll t = x - a[i].first;

    int l = i + 1;
    int r = n - 1;

    while (l < r) {
      ll sum = a[l].first + a[r].first;
      if (sum == t) {
        std::cout << a[i].second << " " 
                  << a[l].second << " " 
                  << a[r].second << std::endl;
        return 0;
      } else if (sum < t) {
        l++;
      } else {
        r--;
      }
    }
  }

  std::cout << "IMPOSSIBLE" << std::endl;

  return 0;
}
