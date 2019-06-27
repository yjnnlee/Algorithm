#include <stdio.h>
int n,m[5], big = 0;
int main(void) {
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &m[i]);
		if(m[i] > big) big = m[i];
	}
	for(int i=1;i<=big;i++){
		if(n==2){
			if(m[1] %i == 0 && m[2] %i ==0){
				printf("%d\n", i);
			}
		}
		else {
			if(m[1] %i == 0 && m[2] %i ==0&&m[3] %i == 0){
				printf("%d\n", i);
			}
		}
	}
}
