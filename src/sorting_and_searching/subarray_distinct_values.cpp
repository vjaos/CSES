#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<ll> x(n);
  for (int i = 0; i != n; ++i) {
    std::cin >> x[i];
  }

  int r = 0;
  ll ans = 0;

  std::unordered_map<int, int> counter;
  for (int l = 0; l != n; ++l) {

    while (r < n && ((int)counter.size() < k || counter.count(x[r]) > 0)) {
      counter[x[r]]++;
      r++;
    }

    ans += r - l;

    counter[x[l]]--;
    if (counter[x[l]] == 0) {
      counter.erase(x[l]);
    }
  }

  std::cout << ans << '\n';

  return 0;
}
