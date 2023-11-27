#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto& e : x) {
        cin >> e;
    }
    int ans = 1 << 30;
    for (int p = 1; p <= 100; p++) {
        int current = 0;
        for (const auto& e : x) {
            current += (e - p) * (e - p);
        }
        if (ans > current) {
            ans = current;
        }
    }
    cout << ans << endl;
    return 0;
}
