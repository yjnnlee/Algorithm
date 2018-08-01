#include <stdio.h>
int n, res = 0;
int main(){
	scanf("%d", &n);
	while (n > 0) {
		if (n % 5) {
			n -= 3;
			res++;
		}
		else {
			res += n / 5;
			break;
		}
	}
	if(n < 0) printf("-1");
	else printf("%d", res);
}

//3씩 빼다가다 5의 배수면 나눠버리면 된다. 음수면 안 된다는 의미임
