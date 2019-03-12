#include <stdio.h>
int a, res = 0, t = 0;
//한수=각 자리수들이 등차수열을 이루는 수 ex) 123
//한자리수와 두자리수는 어떤 숫자가 나오더라도 등차수열이 성립하기 때문에 전부 한수
int main() {
	scanf("%d", &a);
	if (a <= 99) {
		printf("%d", a);
		return 0;
	}
	else {
		for (int i = 100; i <= a; i++) {
			int q = i / 100;
			int w = (i / 10) % 10;
			int e = i % 10;
			if ((e - w) == (w - q)) res++;
		}
		printf("%d", res + 99);
	}
}
