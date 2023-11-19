#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

typedef long long ll;

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  ll x;
  std::cin >> n >> x;

  std::vector<ll> arr(n);
  for (int i = 0; i != n; ++i)
    std::cin >> arr[i];

  std::unordered_map<ll, ll> sums_count;

  ll sum = 0;
  ll res = 0;

  for (int i = 0; i != n; ++i) {
    sum += arr[i];

    if (sum == x)
      res++;

    if (sums_count.find(sum - x) != sums_count.end()) {
      res += sums_count[sum - x];
    }

    sums_count[sum]++;
  }

  std::cout << res << std::endl;

  return 0;
}
