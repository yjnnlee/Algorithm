import sys
n = int(input())
num=[]
for i in range(n):
   a = sys.stdin.readline().split()

   if a[0]=='push':
      num.append(a[1])
   elif a[0]=='pop':
      if not num:
         print(-1)
      else:
         print(num.pop(0))
   elif a[0]=='size':
      print(len(num))
   elif a[0]=='empty':
      if not num:
         print(1)
      else:
         print(0)
   elif a[0]=='front':
      if not num:
         print(-1)
      else:
         print(num[0])
   elif a[0]=='back':
      if not num:
         print(-1)
      else:
         print(num[-1])
