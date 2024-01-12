#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int n;

ll count_path(int i, int j, vector<vector<char>> &grid,
              vector<vector<ll>> &dp) {
  if (i == n - 1 && j == n - 1)
    return 1;
  if (dp[i][j] != -1)
    return dp[i][j];

  dp[i][j] = 0;
  if (i + 1 < n && grid[i + 1][j] != '*') {
    dp[i][j] += count_path(i + 1, j, grid, dp);
    dp[i][j] %= 1'000'000'007;
  }
  if (j + 1 < n && grid[i][j + 1] != '*') {
    dp[i][j] += count_path(i, j + 1, grid, dp);
    dp[i][j] %= 1'000'000'007;
  }

  return dp[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));

  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != n; ++j) {
      cin >> grid[i][j];
    }
  }
  
  vector<vector<ll>> dp(n, vector<ll>(n, -1));
  if (grid[0][0] != '*') {
    cout << count_path(0, 0, grid, dp) << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}