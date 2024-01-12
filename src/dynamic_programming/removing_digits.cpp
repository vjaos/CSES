#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<ll> dp(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int t = i;
    dp[i] = numeric_limits<int>::max();

    while (t) {
      int r = t % 10;
      if (r > 0) {
        dp[i] = min(dp[i], 1 + dp[i - r]);
      }
      t /= 10;
    }
  }

  cout << dp[n] << endl;

  return 0;
}