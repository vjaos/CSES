#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> x(n + 1);
  vector<int> pos(n + 2, 0);
  pos[n + 1] = n + 1;

  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    pos[x[i]] = i;
  }

  int c = 1;
  for (int i = 1; i <= n; i++) {
    if (pos[i - 1] > pos[i])
      c++;
  }

  int a, b;
  while (m-- > 0) {
    cin >> a >> b;
    int x1 = x[a];
    int x2 = x[b];
    swap(x[a], x[b]);

    if (pos[x1 - 1] <= pos[x1] && pos[x1 - 1] > b)
      c++;
    if (pos[x1 - 1] > pos[x1] && pos[x1 - 1] <= b)
      c--;
    if (pos[x1] <= pos[x1 + 1] && b > pos[x1 + 1])
      c++;
    if (pos[x1] > pos[x1 + 1] && b <= pos[x1 + 1])
      c--;
    pos[x1] = b;

    if (pos[x2 - 1] <= pos[x2] && pos[x2 - 1] > b)
      c++;
    if (pos[x2 - 1] > pos[x2] && pos[x2 - 1] <= b)
      c--;
    if (pos[x2] <= pos[x2 + 1] && b > pos[x2 + 1])
      c++;
    if (pos[x2] > pos[x2 + 1] && b <= pos[x2 + 1])
      c--;
    pos[x2] = a;

    cout << c << '\n';
  }

  return 0;
}