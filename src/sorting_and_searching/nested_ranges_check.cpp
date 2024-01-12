#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

struct interval {
  int start;
  int end;
  int idx;

  bool operator<(const interval &other) const {
    return start == other.start ? end > other.end : start < other.start;
  }
};

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  std::vector<interval> ints(n);

  int a, b;
  for (int i = 0; i < n; ++i) {
    std::cin >> a >> b;
    ints[i].start = a;
    ints[i].end = b;
    ints[i].idx = i;
  }

  std::sort(ints.begin(), ints.end());

  int max_end_b = 0;
  std::vector<bool> contained(n);

  for (int i = 0; i < n; ++i) {
    interval s = ints[i];

    if (s.end <= max_end_b) {
      contained[s.idx] = true;
    }
    max_end_b = std::max(max_end_b, s.end);
  }

  std::vector<bool> contains(n);

  int min_end_b = 2e9;
  for (int i = n - 1; i >= 0; i--) {
    interval t = ints[i];
    if (t.end >= min_end_b) {
      contains[t.idx] = true;
    }
    min_end_b = std::min(min_end_b, t.end);
  }

  for (bool v : contains)
    std::cout << v << " ";

  std::cout << '\n';
  for (bool u : contained)
    std::cout << u << " ";

  return 0;
}
