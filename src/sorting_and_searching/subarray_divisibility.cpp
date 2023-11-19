#include <ios>
#include <iostream>
#include <vector>

using ll = long long;

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  ll p_sum = 0;
  int a;
  std::vector<ll> pmod(n); /* contains amount of prefix sums such as psum % n == i */
  pmod[0] = 1;

  for (int i = 0; i != n; ++i) {
    std::cin >> a;
    p_sum += a;
    pmod[((p_sum % n) + n) % n]++;
  }

  ll ans = 0;
  for (ll pmodi : pmod) {
    ans += pmodi * (pmodi - 1) / 2;
  }

  std::cout << ans << std::endl;

  return 0;
}
