n,m = map(int, input().split())
print(int(n//m)) #너무 큰 수가 부모로 있는 / 연산은 런타임 에러가 뜨므로 // 연산해야 한다
print(n%m)
