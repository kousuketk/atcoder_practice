N = int(input())
A = list(map(int, input().split()))

flag = True
for a in A:
    if a % 2 == 1:
        continue
    if a % 3 == 0 or a % 5 == 0:
        continue
    flag = False

if flag:
    print("APPROVED")
else:
    print("DENIED")
