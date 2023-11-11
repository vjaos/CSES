#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<long long> t(n);

  for (int i = 0; i != n; ++i)
    std::cin >> t[i];

  std::sort(t.begin(), t.end());

  long long sum = 0;
  for (int i = 0; i != n - 1; ++i)
    sum += t[i];

  if (sum <= t[n - 1]) {
    std::cout << 2 * t[n - 1] << std::endl;
  } else {
    std::cout << sum + t[n - 1] << std::endl;
  }

  return 0;
}
