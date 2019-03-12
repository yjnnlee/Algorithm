#include <stdio.h>
int a, max = -1;
double num[1001], res = 0;
int main() {
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%lf", &num[i]);
		if (num[i] > max) max = num[i];
	}

	for (int i = 0; i < a; i++) {
		num[i] = num[i] / max * 100;
		res += num[i];	
	}
	printf("%.10g", res/a); //소수점 끝에 의미없는 0은 빼고 출력
}
