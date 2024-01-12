#include <algorithm>
#include <ios>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct interval {
  int a;
  int b;
  bool operator<(interval const &other) const { return b < other.b; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<interval> ints(n);
  for (int i = 0; i != n; ++i) {
    cin >> ints[i].a;
    cin >> ints[i].b;
  }

  sort(ints.begin(), ints.end());

  multiset<int> ends;
  for (int i = 0; i < k; i++)
    ends.insert(0);

  int cnt = 0;
  for (interval const &i : ints) {
    auto it = ends.upper_bound(i.a);
    if (it == ends.begin())
      continue;

    ends.erase(--it);
    ends.insert(i.b);
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}
