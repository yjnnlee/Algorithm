#include <stdio.h>
int n, a, dp0[50]={1,0},dp1[50]={0,1};

int main() {
	for(int i=2;i<=40;i++){
		dp0[i] = dp0[i-2]+dp0[i-1];
		dp1[i] = dp1[i-2]+dp1[i-1];
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		printf("%d %d\n", dp0[a], dp1[a]);
	}
}
//0과 1이 사용된 횟수조차도 피보나치수
