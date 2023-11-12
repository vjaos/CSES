#include <ios>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

typedef long long ll;

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<ll> x(n);

  for (int i = 0; i != n; ++i) {
    std::cin >> x[i];
  }

  std::vector<int> ans(n, 0);
  std::stack<std::pair<int, int>> s;

  for (int i = 0; i != n; ++i) {
    while (!s.empty() && s.top().first >= x[i]) {
      s.pop();
    }

    if (!s.empty()) {
      ans[i] = s.top().second;
    }

    s.push(std::make_pair(x[i], i + 1));
  }

  for (int v : ans)
    std::cout << v << ' ';

  return 0;
}
