#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n, k;
  std::cin >> n;

  std::vector<int> towers;
  for (int i = 0; i < n; i++) {
    std::cin >> k;

    int l = -1;
    int r = (int)towers.size();

    while (l + 1 < r) {
      int m = l + (r - l) / 2;
      if (towers[m] > k)
        r = m;
      else
        l = m;
    }

    if (l + 1 == towers.size())
      towers.push_back(k);
    else
      towers[r] = k;
  }

  std::cout << towers.size() << std::endl;

  return 0;
}
