a = int(input())
str_arr = ["G...", ".I.T", "..S."]

for i in str_arr:
    op = ""
    for j in i:
        op += j * a
    for j in range(a):
        print(op)
        