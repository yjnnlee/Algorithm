#include <stdio.h>
#include <algorithm>
using namespace std;
int n, a[10005], dp[10005];

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	dp[0] = a[0];
	dp[1] = max(a[0]+a[1],a[1]);
	dp[2] = max(max(a[0]+a[2],a[1]+a[2]),a[0]+a[1]);
	for(int i=3;i<n;i++){
		dp[i] = max(max(dp[i-2]+a[i], dp[i-3]+a[i-1]+a[i]),dp[i-1]);
	}
	int tmp = -1;
	for(int i=0;i<n;i++){
		if(tmp<dp[i]) tmp = dp[i];
	}
	printf("%d", tmp);
	
	/*
	O-먹음 X-안먹음
	
	XO+지금꺼먹음(O)VS
	OX+지금꺼먹음(O)VS
	OO+지금꺼안먹음
	
	반례: 2잔 이상 마시지 않는 것이 이득일 경우
	*/
}
