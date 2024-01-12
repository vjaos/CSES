#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<long long> b(m);
    for (int i = 0; i < m; i++) std::cin >> b[i];

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int i = 0;
    int j = 0;
    int cnt = 0;

    while (i < n && j < m) {
        if (std::abs(a[i] - b[j]) <= k) {
            i++;
            j++;
            cnt++;
        } else {
            if (a[i] - k > b[j]) j++;
            else i++;
        }
    }

    std::cout << cnt << std::endl;
}