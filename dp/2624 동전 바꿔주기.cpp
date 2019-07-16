#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, k, coin[105], cnt[105], dp[10005][105];
int f(int total, int n){ //총 금액, 인덱스
	if(total == 0) return 1;
	if(n>=k) return 0;
	
	int &res = dp[total][n];
	if(res!=-1) return res;
	
	res = 0;
	for(int i=0;i<=cnt[n];i++){ //동전의 개수만큼
		if(total-i*coin[n]>=0) res += f(total-i*coin[n], n+1); //동전을 안 쓴다~다 쓴다를 전부 계산
	}
	return res;
}
int main(){
	scanf("%d %d", &t,&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&coin[i], &cnt[i]);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d", f(t,0));
}

/*
개빡치네 이거랑 이거 같은거 아니냐고
왜 다른 값 나와 ㅈㄹㅈㄷㄹㅈㄹ
#include <stdio.h>
#include <cstring>
using namespace std;
int t, k, coin[105], cnt[105], dp[10005][105];

int f(int total, int n){ //총 금액, 인덱스
	if(total == 0) return 1;
	if(n>=k) return 0;
	if(dp[total][n]!=-1) return dp[total][n];
	
	for(int i=0;i<=cnt[n];i++){ //동전의 개수만큼
		if(total-i*coin[n]>=0) dp[total][n] += f(total-i*coin[n], n+1); //동전을 안 쓴다~다 쓴다를 전부 계산
	}
	return dp[total][n];
}
int main(){
	scanf("%d %d", &t,&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&coin[i], &cnt[i]);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d", f(t,0));
}
*/
