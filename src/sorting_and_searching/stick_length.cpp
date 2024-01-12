#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<long long> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];

  sort(p.begin(), p.end());

  long long m = p[n / 2];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(m - p[i]);
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}