#include <stdio.h>
int n,m;
int main(void) {
	scanf("%d %d", &n, &m);
	if(m>=45) {
		printf("%d %d", n, m-45);
	}
	else {
		int tmp = 45 - m;
		m = 60-tmp;
		n--;
		if(n>=0){
			printf("%d %d", n, m);
			return 0;
		}
		else {
			n+=24;
			printf("%d %d", n, m);
		}
	}
	return 0;
}

