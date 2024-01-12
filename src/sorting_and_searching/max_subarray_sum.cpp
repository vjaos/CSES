#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  long long min = 0;
  long long sum = 0;
  long long max = a[0];

  for (int i = 0; i < n; i++) {
    sum += a[i];
    max = std::max(max, sum - min);
    min = std::min(min, sum);
  }

  std::cout << max << std::endl;
  return 0;
}