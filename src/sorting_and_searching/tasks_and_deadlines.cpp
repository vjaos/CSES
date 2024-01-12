#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

struct task {
  long long dur;
  long long deadline;

  bool operator<(const task &other) const { return dur < other.dur; }
};

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<task> tasks(n);
  for (int i = 0; i != n; ++i) {
    std::cin >> tasks[i].dur;
    std::cin >> tasks[i].deadline;
  }

  std::sort(tasks.begin(), tasks.end());

  long long finish = 0;
  long long profit = 0;

  for (task &t : tasks) {
    finish += t.dur;
    profit += t.deadline - finish;
  }

  std::cout << profit << std::endl;

  return 0;
}
