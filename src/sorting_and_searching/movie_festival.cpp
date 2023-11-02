#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  int a, b;
  std::vector<std::pair<int, int>> events;
  for (int i = 0; i < n; i++) {
    std::cin >> a >> b;
    events.push_back(std::make_pair(a, b));
  }

  auto cmp = [](std::pair<int, int> x, std::pair<int, int> y) {
    return x.second < y.second;
  };

  std::sort(events.begin(), events.end(), cmp);

  int cnt = 0;
  auto last = std::make_pair(-1, -1);
  for (auto &e : events) {
    if (last.second <= e.first) {
      cnt++;
      last = e;
    }
  }

  std::cout << cnt << std::endl;
}