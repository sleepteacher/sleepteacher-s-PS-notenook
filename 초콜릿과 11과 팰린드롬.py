N = int(input())
for i in range(N):
    a = int(input())
    if a == 1:
        print(0)
    elif a == 2:
        print(11)
    elif a == 3:
        print(121)
    else:
        print("11"+"0"*(a-4)+"11")
                
                
            