import sys

input = sys.stdin.readline
N= int(input())
L = [0 for i in range(N)]
for i in range(N):
    L[i] = int(input())
L.sort()
result=0
for i in range(2,N):
    result = max(abs(3*L[i-1]-(L[0]+L[i-1]+L[i])),result)
    result = max(abs(3*L[i-1]-(L[i-2]+L[i-1]+L[N-1])),result)

print(result)