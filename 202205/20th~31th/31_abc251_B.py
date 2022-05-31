# 良い整数をsetに入れていく
N, W = map(int, input().split())
A = list(map(int, input().split()))


def judge(sum, s):
    if sum <= W:
        s.add(sum)


s = set([])
for i in range(0, N):
    judge(A[i], s)
    for j in range(i + 1, N):
        judge(A[i] + A[j], s)
        for k in range(j + 1, N):
            judge(A[i] + A[j] + A[k], s)

ans = len(s)
print(ans)
