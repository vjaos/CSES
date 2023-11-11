#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

struct customer {
  int in;
  int out;
  int i;

  bool operator<(const customer &other) const { return in < other.in; }
};

int main(int argc, char *argv[]) {

  int n;
  std::cin >> n;
  std::vector<customer> events(n);

  for (int i = 0; i < n; i++) {
    std::cin >> events[i].in;
    std::cin >> events[i].out;
    events[i].i = i;
  }

  std::sort(events.begin(), events.end());

  int rooms = 0, last_room_id = 0;
  std::vector<int> ans(n);
  std::priority_queue<std::pair<int, int>> pq;

  for (customer &cus : events) {

    if (pq.empty()) {
      ++last_room_id;
      pq.push(std::make_pair(-cus.out, last_room_id));
      ans[cus.i] = last_room_id;
    } else {
      auto [out, room_id] = pq.top();
      if (-pq.top().first < cus.in) {
        pq.pop();
        pq.push(std::make_pair(-cus.out, room_id));
        ans[cus.i] = room_id;
      } else {
        ++last_room_id;
        pq.push(std::make_pair(-cus.out, last_room_id));
        ans[cus.i] = last_room_id;
      }
    }

    rooms = std::max(rooms, (int)pq.size());
  }

  std::cout << rooms << '\n';
  for (int i = 0; i != ans.size(); i++) {
    std::cout << ans[i] << ' ';
  }

  return 0;
}
