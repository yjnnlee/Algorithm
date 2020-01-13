n=int(input())
res=0

for i in range(1,n+1):
    for j in range(i,i+i+1):
        res+=j

print(res)
        
'''
N=3이라면 점의 수는

1 2
2 3 4
3 4 5 6

총 30개

다른 사람 답: print(n*(n+1)*(n+2)//2)
'''
