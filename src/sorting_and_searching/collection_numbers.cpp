#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> x(n);
  vector<int> pos(n + 1);
  vector<bool> used(n + 1);

  for (int i = 0; i < n; i++) {
    cin >> x[i];
    pos[x[i]] = i;
  }

  int cnt = 0;
  int curr_pos = 0;
  for (int i = 0; i < n; i++) {
    if (!used[x[i]]) {
      cnt++;
      used[x[i]] = true;
      curr_pos = i;
      while (x[curr_pos] + 1 <= n && !used[x[curr_pos] + 1] &&
             pos[x[curr_pos] + 1] > pos[x[curr_pos]]) {
        used[x[curr_pos] + 1] = true;
        curr_pos = pos[x[curr_pos] + 1];
      }
    }
  }

  cout << cnt << endl;
  return 0;
}