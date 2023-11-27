#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0, taps = 1;
    while (taps < b) {
        taps += a - 1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
