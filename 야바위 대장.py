S = input()
T = int(input())
for i in range(T):
    a, b = map(int,input().split())
    ori = S
    ori[a-1] = S[b-1]
    ori[b-1] = S[a-1] 
    S = ori
print(S)