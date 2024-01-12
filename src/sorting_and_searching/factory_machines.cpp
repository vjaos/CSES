#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n;
  long long t;
  std::cin >> n >> t;

  std::vector<int> perf(n);
  for (int i = 0; i != n; i++) {
    std::cin >> perf[i];
  }

  long long l = 0;
  long long r = 1e18;
  long long m;

  while (l + 1 < r) {
    m = l + (r - l) / 2;

    long long sum = 0;
    for (int i = 0; i != n; ++i) {
      sum += m / perf[i];
      if (sum >= t) {
        break;
      }
    }

    if (sum >= t) {
      r = m;
    } else {
      l = m;
    }
  }

  std::cout << r << std::endl;

  return 0;
}
