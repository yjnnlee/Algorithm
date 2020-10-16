n=list(map(int, input().split()))
m=[1,1,2,2,2,8]
for i in range(0, len(n)):
   print(m[i]-n[i], end=' ')
