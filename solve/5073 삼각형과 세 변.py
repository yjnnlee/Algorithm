
while True:
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    
    if a[0]+a[1]+a[2] == 0:
        break
    elif a[0]>=a[1]+a[2]:
        print("Invalid")    
    elif a.count(a[0]) == 3:
        print("Equilateral")
    elif a.count(a[0])==2 or a.count(a[1])==2 or a.count(a[2])==2:
        print("Isosceles")
    else:
        print("Scalene")
