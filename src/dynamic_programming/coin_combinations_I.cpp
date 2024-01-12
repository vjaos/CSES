#include <ios>
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

  vector<int> coins(n);
  for (int i = 0; i != n; ++i)
    cin >> coins[i];

  vector<ll> dp(x + 1, 0);

  dp[0] = 1;
  for (int i = 1; i <= x; ++i) {
    for (int c : coins) {
      if (i - c >= 0) {
        dp[i] += dp[i - c];
        dp[i] %= 1'000'000'007;
      }
    }
  }

  cout << dp[x] << endl;

  return 0;
}
