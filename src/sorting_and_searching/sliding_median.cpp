#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct sliding_median {
  multiset<int, greater<int>> maxQ;
  multiset<int, less<int>> minQ;

  void add(int x) {
    if (maxQ.empty() || x <= *maxQ.begin()) {
      maxQ.insert(x);
    } else {
      minQ.insert(x);
    }

    if (maxQ.size() + 1 > minQ.size()) {
      auto it = maxQ.begin();
      int val = *it;

      maxQ.erase(it);
      minQ.insert(val);
    }

    if (minQ.size() > maxQ.size()) {
      auto it = minQ.begin();
      int val = *it;

      minQ.erase(it);
      maxQ.insert(val);
    }
  }

  void remove(int x) {
    if (x <= *maxQ.begin()) {
      maxQ.extract(x);
    } else {
      minQ.extract(x);
    }
  }

  int median() { return *maxQ.begin(); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> x(n);
  for (int i = 0; i != n; ++i)
    cin >> x[i];

  sliding_median md;

  int l = 0;
  for (int r = 0; r != n; ++r) {
    md.add(x[r]);

    if (r - l + 1 == k) {
      cout << md.median() << " ";
      md.remove(x[l]);
      l++;
    }
  }

  return 0;
}