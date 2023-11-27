#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0, taps = 1;
    while (taps < b) {
        taps += a - 1;
        ans++;
    }
    printf("%d\n", ans);
}
