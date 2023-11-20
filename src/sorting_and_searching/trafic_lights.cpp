#include <ios>
#include <iostream>
#include <set>

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int x, n;
  std::cin >> x >> n;
  std::set<int> lights{0, x};
  std::multiset<int> dist{x};

  int p;
  for (int i = 0; i < n; i++) {
    std::cin >> p;
    auto next = lights.upper_bound(p);
    auto prev = next;
    --prev;

    dist.erase(dist.find(*next - *prev));
    dist.insert(p - *prev);
    dist.insert(*next - p);
    lights.insert(p);

    auto ans = dist.end();
    --ans;
    std::cout << *ans << " ";
  }
  return 0;
}
