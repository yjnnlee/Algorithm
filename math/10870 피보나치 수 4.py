n=int(input())
a=0
b=1
c=1
for i in range(1,n):
    ta=b
    tb=c
    tc=b+c
    a=ta
    b=tb
    c=tc
    
if n == 0:
    print(0)
else:
    print(b)
