#include <stdio.h>
#define MOD 1000000000
int num, cnt = 0, res = 0;
int f(int n, int now){
	if(n==1) return 1;	
	
	if(now == 0) return cnt = f(n-1,1)%MOD;
	if(now == 9) return cnt = f(n-1,8)%MOD;
	else return cnt = f(n-1, now+1)+f(n-1,now-1)%MOD;
}
int main() {
	scanf("%d", &num);
	for(int i=1;i<=9;i++){
		res += f(num, i)%MOD; //자리수, 현재 숫자
	}
	printf("%d", res);
}
