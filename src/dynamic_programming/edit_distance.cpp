
#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a, b;
int n, m;

int edit_distance(int i, int j, vector<vector<int>> &dp) {
  if (i == n && j == m)
    return 0;
  if (i == n && j < m)
    return m - j;
  if (i < n && j == m)
    return n - i;

  if (dp[i][j] != -1)
    return dp[i][j];

  dp[i][j] = 0;
  if (a[i] == b[j]) {
    dp[i][j] = edit_distance(i + 1, j + 1, dp);
  } else {
    dp[i][j] =
        1 + min(min(edit_distance(i + 1, j, dp), edit_distance(i, j + 1, dp)),
                edit_distance(i + 1, j + 1, dp));
  }
  return dp[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> a >> b;

  n = static_cast<int>(a.size());
  m = static_cast<int>(b.size());
  vector<vector<int>> dp(n, vector<int>(m, -1));

  cout << edit_distance(0, 0, dp) << endl;
  return 0;
}
