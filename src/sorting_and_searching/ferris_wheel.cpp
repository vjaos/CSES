#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  long long x;

  std::cin >> n >> x;
  std::vector<long long> p(n);
  std::vector<bool> has_gondola(n);

  for (int i = 0; i < n; i++)
    std::cin >> p[i];

  std::sort(p.begin(), p.end());

  int cnt = 0;
  int i = 0;
  int j = n - 1;

  while (i < j) {
    if (p[i] + p[j] > x) {
      j--;
    } else {
      cnt++;
      has_gondola[i] = has_gondola[j] = true;

      i++;
      j--;
    }
  }

  for (int i = 0; i < n; i++) {
    if (!has_gondola[i])
      cnt++;
  }

  std::cout << cnt << std::endl;
}