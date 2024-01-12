#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

int dfs(int a, int b, vector<vector<int>> &dp) {
  if (a == b)
    return 0;
  if (dp[a][b] != -1)
    return dp[a][b];

  dp[a][b] = numeric_limits<int>::max();
  for (int i = 1; i != a; ++i) {
    dp[a][b] = min(dp[a][b], 1 + dfs(i, b, dp) + dfs(a - i, b, dp));
  }

  for (int i = 1; i != b; ++i) {
    dp[a][b] = min(dp[a][b], 1 + dfs(a, i, dp) + dfs(a, b - i, dp));
  }

  return dp[a][b];
}

int main() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }

  vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

  for (int h = 1; h <= a; ++h) {
    for (int w = 1; w <= b; ++w) {
      if (h == w)
        continue;
      dp[h][w] = numeric_limits<int>::max();

      for (int k = 1; k != w; ++k) {
        dp[h][w] = min(dp[h][w], 1 + dp[h][k] + dp[h][w - k]);
      }

      for (int k = 1; k != h; ++k) {
        dp[h][w] = min(dp[h][w], 1 + dp[k][w] + dp[h - k][w]);
      }
    }
  }

  cout << dp[a][b] << endl;

  return 0;
}
