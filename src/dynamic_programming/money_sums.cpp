#include <ios>
#include <iostream>
#include <vector>

using namespace std;

const int MAXSUM = 1e5;
const int MAXN = 100;

bool dp[MAXN + 1][MAXSUM + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<int> x(n);
  for (int i = 0; i != n; ++i) {
    cin >> x[i];
  }

  dp[0][0] = true;

  for (int i = 1; i <= n; ++i) {
    for (int sum = 0; sum <= MAXSUM; ++sum) {
      dp[i][sum] = dp[i - 1][sum];

      int prev = sum - x[i - 1];
      if (prev >= 0 && dp[i - 1][prev]) {
        dp[i][sum] = true;
      }
    }
  }

  vector<int> sums;
  for (int sum = 1; sum <= MAXSUM; ++sum) {
    if (dp[n][sum]) {
      sums.push_back(sum);
    }
  }

  cout << sums.size() << "\n";
  for (auto v : sums) {
    cout << v << " ";
  }
  cout << "\n";
  return 0;
}
