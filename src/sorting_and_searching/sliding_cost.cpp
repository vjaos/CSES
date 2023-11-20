#include <ios>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

struct sliding_median {
  ll maxS = 0;
  ll minS = 0;

  multiset<int, greater<int>> maxQ;
  multiset<int, less<int>> minQ;

  void add(int x) {
    if (maxQ.empty() || x <= *maxQ.begin()) {
      maxQ.insert(x);
      maxS += x;
    } else {
      minQ.insert(x);
      minS += x;
    }

    if (maxQ.size() + 1 > minQ.size()) {
      auto it = maxQ.begin();
      int val = *it;

      maxQ.erase(it);
      maxS -= val;
      minQ.insert(val);
      minS += val;
    }

    if (minQ.size() > maxQ.size()) {
      auto it = minQ.begin();
      int val = *it;

      minQ.erase(it);
      minS -= val;
      maxQ.insert(val);
      maxS += val;
    }
  }

  void remove(int x) {
    if (x <= *maxQ.begin()) {
      maxS -= x;
      maxQ.extract(x);
    } else {
      minS -= x;
      minQ.extract(x);
    }
  }

  ll cost() {
    ll size = static_cast<ll>(maxQ.size() + minQ.size());
    ll m = size % 2 == 0 ? 0 : *maxQ.begin();

    return minS - maxS + m;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> x(n);

  for (int i = 0; i != n; ++i) {
    cin >> x[i];
  }

  sliding_median md;

  int l = 0;
  for (int r = 0; r != n; ++r) {
    md.add(x[r]);

    if (r - l + 1 == k) {
      ll d = md.cost();

      cout << d << " ";
      md.remove(x[l]);
      l++;
    }
  }

  return 0;
}
