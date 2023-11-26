#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> seen;

int count(int x, const vector<int> &cs) {

  if (x < 0)
    return 0;

  if (seen[x])
    return 0;

  if (x == 0)
    return 1;

  int ans = 0;
  for (int c : cs) {
    if (x - c >= 0) {
      ans += count(x - c, cs);
      ans %= 1'000'000'007;
    }
  }

  seen[x] = true;
  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  seen.assign(x + 1, false);

  for (int i = 0; i != n; ++i) {
    cin >> coins[i];
  }

  int cnt = count(x, coins);

  cout << cnt << '\n';

  return 0;
}
