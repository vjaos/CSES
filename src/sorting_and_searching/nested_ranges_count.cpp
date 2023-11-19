#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

struct range {
  int a;
  int b;
  int i;

  bool operator<(const range &other) const {
    if (a == other.a)
      return b > other.b;
    return a < other.a;
  }
};

struct fenwick {
  std::vector<int> bit;
  int n;

  fenwick(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  int sum(int l, int r) { return sum(r) - sum(l - 1); }

  void add(int idx, int val) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += val;
  }
};

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  std::set<int> left_bounds;
  std::vector<range> ranges(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> ranges[i].a;
    std::cin >> ranges[i].b;
    ranges[i].i = i;
    left_bounds.insert(ranges[i].b);
  }

  std::unordered_map<int, int> map;
  map.reserve(left_bounds.size());
  int idx = 0;
  for (int b : left_bounds) {
    map[b] = idx;
    idx++;
  }

  std::sort(ranges.begin(), ranges.end());

  fenwick bit1(n);

  std::vector<int> contains(n);

  for (int i = n - 1; i >= 0; --i) {
    range rng = ranges[i];
    int idx = map[rng.b];

    // count of ranges such as left_bound <= this.left_bound
    contains[rng.i] = bit1.sum(idx);
    bit1.add(idx, 1);
  }

  for (int u : contains)
    std::cout << u << " ";

  std::cout << "\n";

  fenwick bit(n);
  std::vector<int> contained(n);
  for (const range &x : ranges) {
    int key = map[x.b];

    // count of ranges such as this.left_bound >= left_bound
    contained[x.i] = bit.sum(key, n);
    bit.add(key, 1);
  }

  for (int v : contained)
    std::cout << v << " ";

  return 0;
}
