#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

struct minqueue {
  // (val, min)
  stack<pair<ll, ll>> in;
  stack<pair<ll, ll>> out;

  void push(ll v) {
    ll min_val = in.empty() ? LONG_MAX : in.top().second;
    in.push(make_pair(v, min(min_val, v)));
  }

  void pop() {
    if (out.empty()) {
      while (!in.empty()) {
        ll curr_min_val = out.empty() ? LONG_MAX : out.top().second;
        ll val = in.top().first;

        out.push(make_pair(val, min(curr_min_val, val)));
        in.pop();
      }
    }

    out.pop();
  }

  ll getmin() {
    ll in_min = in.empty() ? LONG_MAX : in.top().second;
    ll out_min = out.empty() ? LONG_MAX : out.top().second;
    return min(in_min, out_min);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;

  vector<ll> pfx(n + 1, 0);

  int v;
  for (int i = 1; i <= n; ++i) {
    cin >> v;
    pfx[i] = pfx[i - 1] + v;
  }

  ll max_sum = LONG_MIN;
  minqueue mq;

  for (int i = a; i <= n; i++) {
    if (i > b) {
      mq.pop();
    }
    mq.push(pfx[i - a]);
    max_sum = max(max_sum, pfx[i] - mq.getmin());
  }

  cout << max_sum << '\n';
  return 0;
}
