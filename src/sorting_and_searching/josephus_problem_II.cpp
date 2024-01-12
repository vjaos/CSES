#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

/* TLE solution */
int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> child(n);

  for (int i = 0; i < n; i++)
    child[i] = i + 1;

  int i = 0;
  while (child.size() != 0) {
    i += k;
    i = i % child.size();

    auto it = child.begin() + i;
    std::cout << *it << ' ';

    child.erase(it);
  }

  return 0;
}
