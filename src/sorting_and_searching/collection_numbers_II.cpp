#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> x(n + 1);
  vector<int> pos(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    pos[x[i]] = i;
  }

  int c = 1;
  for (int i = 1; i <= n; i++) {
    if (pos[i - 1] > pos[i]) c++;
  }

  int a, b;
  while (m-- > 0) {
    cin >> a >> b;
    int x1 = x[a];
    int x2 = x[b];
      
  }

  return 0;
}