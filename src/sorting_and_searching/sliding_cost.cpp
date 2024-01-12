#include <ios>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

struct sliding_median {
  ll lower_sum = 0;
  ll upper_sum = 0;

  multiset<int, greater<int>> maxQ;
  multiset<int, less<int>> minQ;

  void add(int x) {
    if (maxQ.empty() || x <= *maxQ.begin()) {
      maxQ.insert(x);
      lower_sum += x;
    } else {
      minQ.insert(x);
      upper_sum += x;
    }

    if (maxQ.size() + 1 > minQ.size()) {
      auto it = maxQ.begin();
      int val = *it;

      maxQ.erase(it);
      lower_sum -= val;
      minQ.insert(val);
      upper_sum += val;
    }

    if (minQ.size() > maxQ.size()) {
      auto it = minQ.begin();
      int val = *it;

      minQ.erase(it);
      upper_sum -= val;
      maxQ.insert(val);
      lower_sum += val;
    }
  }

  void remove(int x) {
    if (x <= *maxQ.begin()) {
      lower_sum -= x;
      maxQ.extract(x);
    } else {
      upper_sum -= x;
      minQ.extract(x);
    }
  }

  ll cost() {
    ll size = static_cast<ll>(maxQ.size() + minQ.size());
    ll m = size % 2 == 0 ? 0 : *maxQ.begin();

    return upper_sum - lower_sum + m;
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
