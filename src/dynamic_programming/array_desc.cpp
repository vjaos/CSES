#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
int MOD = 1'000'000'007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i != n; ++i) {
    cin >> arr[i];
  }

  // dp[i][j] кол-во способов заполнить массив до i позиции значеним j
  vector<vector<int>> dp(n, vector<int>(m + 1, 0));

  if (arr[0] == 0) {
    for (int i = 1; i <= m; i++) {
      dp[0][i] = 1;
    }
  } else {
    dp[0][arr[0]] = 1;
  }

  for (int i = 1; i < n; ++i) {
    if (arr[i] == 0) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = dp[i - 1][j];
        dp[i][j] %= MOD;

        if (j - 1 > 0) {
          dp[i][j] += dp[i - 1][j - 1];
          dp[i][j] %= MOD;
        }
        if (j + 1 <= m) {
          dp[i][j] += dp[i - 1][j + 1];
          dp[i][j] %= MOD;
        }
      }
    } else {
      dp[i][arr[i]] += dp[i - 1][arr[i]];
      dp[i][arr[i]] %= MOD;
      if (arr[i] - 1 > 0) {
        dp[i][arr[i]] += dp[i - 1][arr[i] - 1];
        dp[i][arr[i]] %= MOD;
      }
      if (arr[i] + 1 <= m) {
        dp[i][arr[i]] += dp[i - 1][arr[i] + 1];
        dp[i][arr[i]] %= MOD;
      }
    }
  }

  ll ans = 0;

  for (int i = 1; i <= m; ++i) {
    ans += dp[n - 1][i];
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}