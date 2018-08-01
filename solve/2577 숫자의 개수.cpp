#include <stdio.h>
int num[10], a, b, c;
long long res = 0;
int main(){
	scanf("%d%d%d", &a,&b,&c);
	res = (long long)a*b*c;
	while (res > 0) {
		num[(int)res % 10]++;
		res /= 10;
	}
	for (int i = 0; i <= 9; i++) {
		printf("%d\n", num[i]);
	}
}
