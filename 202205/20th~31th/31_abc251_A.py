s = input()

while len(s) < 6:
    s += s

ans = s[0:6]
print(ans)
