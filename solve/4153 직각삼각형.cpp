#include <stdio.h>
int n,m,k;
int main(void) {
	while(1){
	scanf("%d%d%d", &n, &m, &k);
	if(n==0 && m==0 &&k==0) return 0;
	if(n*n + m*m == k*k || n*n + k*k ==m*m || k*k+m*m==n*n) printf("right\n");
	else printf("wrong\n");
	}
}
