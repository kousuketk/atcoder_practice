N = int(input())

ans = 0
max_val = 0
d = {}

for i in range(N):
    key, score = input().split()
    score = int(score)
    if key in d:
        continue
    d[key] = score
    if max_val < score:
        max_val = score
        ans = i

print(ans + 1)
