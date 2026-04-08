while 1:
    L = input()
    if L == "#":
        break
    else:
        L = L.lower()
        print(L.count('a')+L.count('e')+L.count('i')+L.count('o')+L.count('u'))