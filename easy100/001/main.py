a, b = map(int, input().split())
ans = 0
taps = 1
while taps < b:
    taps += a - 1
    ans += 1
print(ans)
