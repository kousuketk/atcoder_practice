a, b, c = map(int, input().split())
st = set()
st.add(a)
st.add(b)
st.add(c)
if len(st) == 2:
    print("Yes")
else:
    print("No")
