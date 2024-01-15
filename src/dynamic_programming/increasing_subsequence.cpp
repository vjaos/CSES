#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, x;
  cin >> n;

  vector<int> dp;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    auto it = lower_bound(dp.begin(), dp.end(), x);
    if (it == dp.end()) {
      dp.push_back(x);
    } else {
      *it = x;
    }
  }

  cout << dp.size() << "\n";

  return 0;
}
