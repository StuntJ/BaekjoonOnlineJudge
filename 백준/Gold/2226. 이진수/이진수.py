N = int(input())
ans = 0

for i in range(1, N):
    if i % 2 == 1:
        ans = ans * 2 + 1
    else:
        ans = ans * 2 - 1

print(ans)