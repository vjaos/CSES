#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> k(n);
  unordered_map<int, int> cnt;
  cnt.reserve(300'000);

  for (int i = 0; i < n; i++) {
    cin >> k[i];
    if (cnt.find(k[i]) == cnt.end()) {
      cnt[k[i]] = 0;
    }
  }

  int l = 0;
  int max_ans = 0;
  for (int r = 0; r < n; r++) {
    cnt[k[r]]++;
    while (l < r && cnt[k[r]] > 1) {
      cnt[k[l]]--;
      l++;
    }
    max_ans = max(max_ans, r - l + 1);
  }

  cout << max_ans << endl;

  return 0;
}