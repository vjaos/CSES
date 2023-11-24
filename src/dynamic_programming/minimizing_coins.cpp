#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  using ll = long long;

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i != n; ++i)
    cin >> coins[i];

  vector<ll> dp(x + 1, 0);
  dp[0] = 0;

  for (int i = 1; i <= x; ++i) {
    dp[i] = LONG_MAX;
    for (int c : coins) {
      if (i - c >= 0 && dp[i - c] != LONG_MAX) {
        dp[i] = min(dp[i], 1 + dp[i - c]);
      }
    }
  }

  if (dp[x] == LONG_MAX)
    cout << "-1" << endl;
  else
    cout << dp[x] << endl;

  return 0;
}
