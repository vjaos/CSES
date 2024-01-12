#include <ios>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  std::vector<int> child;

  for (int i = 1; i <= n; i++)
    child.push_back(i);

  while (child.size() > 1) {
    std::vector<int> surv;

    for (int i = 0; i < child.size(); i++) {
      if (i % 2) {
        std::cout << child[i] << " ";
      } else {
        surv.push_back(child[i]);
      }
    }

    if (child.size() % 2 == 0) {
      child = surv;
    } else {
      int start = surv.back();

      surv.pop_back();
      child.clear();
      child.push_back(start);

      for (int v : surv)
        child.push_back(v);
    }
  }
  std::cout << child[0];
  return 0;
}
