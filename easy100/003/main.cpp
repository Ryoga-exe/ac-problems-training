#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int domestic = 0, international = 0;
    for (const auto& c : s) {
        bool passed = false;
        if (c == 'a') {
            if (domestic + international < a + b) {
                domestic++;
                passed = true;
            }
        }
        else if (c == 'b') {
            if (domestic + international < a + b && international < b) {
                international++;
                passed = true;
            }
        }
        cout << (passed ? "Yes" : "No") << endl;
    }
}
