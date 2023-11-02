#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> events;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    events.push_back(pair(a, 1));
    events.push_back(pair(b, -1));
  }

  auto cmp = [](pair<int, int> x, pair<int, int> y) {
    return x.first < y.first;
  };

  sort(events.begin(), events.end(), cmp);

  int cnt = 0;
  int max = 0;
  for (pair<int, int> e : events) {
    cnt += e.second;
    if (cnt > max) {
      max = cnt;
    }
  }

  cout << max << endl;
}