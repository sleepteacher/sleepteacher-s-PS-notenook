N = int(input())
arr = []
for i in range(N):
    a = list(input().split())
    arr.append(a)
result = 0
def DFS(x, y, value):
    
    if (x+1 < N):
        DFS(x+1,y,value+arr[x+1][y])
    if (y+1 < N):
        DFS(x,y+1,value+arr[x][y+1])
    global result 
    result = max(int('0b'+value,2),result)
DFS(0,0,arr[0][0])
print(result)
print(arr)