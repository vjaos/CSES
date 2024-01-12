#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> h(n), s(n);
  for (int i = 0; i != n; ++i) {
    cin >> h[i];
  }
  for (int i = 0; i != n; ++i) {
    cin >> s[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  for (int k = 1; k <= n; ++k) {
    for (int w = 1; w <= x; ++w) {
      dp[k][w] = dp[k - 1][w];
      if (w >= h[k - 1]) {
        dp[k][w] = max(dp[k][w], dp[k - 1][w - h[k - 1]] + s[k - 1]);
      }
    }
  }

  cout << dp[n][x] << "\n";

  return 0;
}