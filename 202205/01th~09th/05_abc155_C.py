N = int(input())
max_val = 0
dic = {}
for i in range(N):
    s = input()
    if s in dic:
        dic[s] += 1
    else:
        dic[s] = 1
    max_val = max(max_val, dic[s])
dic2 = sorted(dic.items())
for k in dic2:
    if k[1] == max_val:
        print(k[0])
