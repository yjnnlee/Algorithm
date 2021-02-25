while True:
    try: n = int(input())
    except: break

    dp=[0]*251
    dp[0]=1 #2x0을 채우는 방법은 "아무것도 하지 않는다" 1개
    dp[1]=1
    dp[2]=3
    dp[3]=5
    for i in range(4, 251):
        dp[i]=dp[i-1]+dp[i-2]*2

    print(dp[n])
    
