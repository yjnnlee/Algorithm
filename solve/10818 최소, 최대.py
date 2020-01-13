n=int(input())
a=[]

a = list(map(int, input().split()))
a.sort()
print("%d %d"% (a[0], a.pop()))
