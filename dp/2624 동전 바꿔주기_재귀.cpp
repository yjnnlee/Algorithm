#include <stdio.h>
int t, k, coin[105], cnt[105], res = 0, sum = 0, dp[10005][105];
int f(int total, int n){ //총 금액, 인덱스
	if(total == t) return 1;
	if(n<=0) return 0;
	
	int sum = 0; //dp를 안 썼을 때 왜 여기를 0으로 해줘야 하지??
	for(int i=0;i<=cnt[n];i++){ //동전의 개수만큼
		sum += f(total+i*coin[n], n-1); //동전을 안 쓴다~다 쓴다를 전부 계산
	}
	return sum;
}
int main(){
	scanf("%d%d", &t,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&coin[i], &cnt[i]);
	}
	printf("%d", f(0,k));
}
