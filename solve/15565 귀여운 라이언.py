n, k=map(int, input().split())
#n=int(input())
#s=list(map(int, input().split()))
s=input().split()
res=0
if s.count('1')<k:
    print(-1)
else:
    lion=[i for i, v in enumerate(s) if v=='1'] #라이언 인덱스만 뽑음
    #for x in lion: print(x)
    #len(lion)-k+1로 반 나눠서, 위에 반-아래 반의 길이 중 min값
    print(min(lion[k-1+j]-lion[j]+1 for j in range(len(lion)-k+1)))
    #for x in range(len(lion)-k+1): print(lion[k-1+x])
