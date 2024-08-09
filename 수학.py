def gcd(a, b):
    if a < b:
        a,b = b,a
    if a % b == 0:
        return b
    else:
        return gcd(a%b, b)

n, m = map(int, input().split())
D = list(map(int, input().split()))
M = list(map(int, input().split()))


while len(D) > 1:
    a,b = D.pop(),D.pop()
    D.append((a//gcd(a,b))*b)
while len(M) > 1:
    a,b = M.pop(),M.pop()
    M.append(gcd(a,b))
a, b = D.pop(), M.pop()
if(b <= a):
    print(int(b%a == 0))
else:
    if(b % a):
        print(0)
    else:
        result = 0
        iter = 2
        root = 0
        b //= a
        origin = b
        while(1):     
            if(origin % iter == 0):
                root = 0
                while(b % iter == 0):
                    root += 1
                    b //= iter
                if(result):
                    result *= root+1
                else:
                    result = root+1
            if((iter+1) * (iter+1) > origin):
                break
            iter += 1
        if(b != 1):
            if(result):
                result *= 2
            else:
                result = 2
        print(result)
                    
# 6/12