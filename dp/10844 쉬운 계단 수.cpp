#include <stdio.h>
#define MOD 1000000000
int num, dp[105][10];
long long res = 0;
int f(int n, int now){
	if(n==1) return 1;
	if(dp[n][now]) return dp[n][now];
	
	if(now == 0) return dp[n][now] = f(n-1,1)%MOD;
	else if(now == 9) return dp[n][now] = f(n-1,8)%MOD;
	else return dp[n][now] = (f(n-1, now+1)+f(n-1,now-1))%MOD;
}
int main() {
	scanf("%d", &num);
	if(num == 1){
		printf("9");
		return 0;
	}
	for(int i=1;i<=9;i++){
		res += (f(num, i)%MOD); //자리수, 현재 숫자
	}
	printf("%lld", res%MOD);
}
