#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  using ll = long long;

  int n;
  cin >> n;
  ll sum = 0;

  vector<int> x(n);
  for (int i = 0; i != n; ++i) {
    cin >> x[i];
    sum += x[i];
  }

  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  for (int l = n - 1; l >= 0; --l) {
    for (int r = l; r != n; ++r) {
      if (l == r) {
        dp[l][r] = x[l];
      } else {
        dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
      }
    }
  }

  cout << ((sum + dp[0][n - 1]) / 2) << "\n";

  return 0;
}
