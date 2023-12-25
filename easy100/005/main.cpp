#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for (auto& e : b) {
        cin >> e;
    }
    int ans = 0;
    while (n--) {
        int value = c;
        for (const auto e : b) {
            int a;
            cin >> a;
            value += e * a;
        }
        if (value > 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
