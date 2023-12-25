#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int x = 0; x <= n; x++) {
        if (x * 108 / 100 == n) {
            cout << x << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}
