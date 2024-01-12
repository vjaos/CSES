#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<long long> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];

  sort(x.begin(), x.end());

  long long sum = 0;

  for (int i = 0; i != n; i++) {
    if (sum + 1 < x[i])
      break;
    sum += x[i];
  }

  cout << sum + 1 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}