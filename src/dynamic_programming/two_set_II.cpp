#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  using ll = long long;

  ll trg = n * (n + 1) / 2;

  if (trg % 2) {
    cout << 0 << "\n";
    return 0;
  }

  trg /= 2;
  vector<vector<ll>> dp(n + 1, vector<ll>(trg + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i != n; ++i) {
    for (int sum = 0; sum <= trg; ++sum) {
      dp[i][sum] = dp[i - 1][sum];
      if (sum - i >= 0) {
        dp[i][sum] += dp[i - 1][sum - i];
        dp[i][sum] %= 1'000'000'007;
      }
    }
  }

  cout << dp[n - 1][trg] << "\n";
}
