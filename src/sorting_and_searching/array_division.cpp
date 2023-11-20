#include <iostream>
#include <ios>
#include <vector>

using namespace std;

using ll = long long;

bool is_good(const vector<ll> &arr, int k, ll sum) {
  int count = 0;
  ll curr_sum = 0;

  for (int x : arr) {
    if (x > sum) return false;

    if (curr_sum + x > sum) {
      count++;
      curr_sum = 0;
    }
    curr_sum += x;
  }

  if (curr_sum > 0)
    ++count;

  return count <= k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<ll> x(n);
  for (int i = 0; i != n; ++i) {
    cin >> x[i];
  }

  ll l = -1;
  ll r = 2e5 * 1e9;

  while (l + 1 < r) {
    ll m = l + (r - l) / 2;
    if (is_good(x, k, m)) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r << endl;
  return 0;
}