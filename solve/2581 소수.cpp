#include <stdio.h>
int a, b, sosu[10001], res;
long long int sum = 0;
bool chk = true;

int main() {
	scanf("%d %d", &a, &b);
	for (int i = 2; i <= b; i++) {
		sosu[i] = i;
	}
	
	for (int i = 2; i <= b; i++) {
		if (sosu[i] == 0) continue;
		for (int j = i + i; j <= b; j+=i) {
			sosu[j] = 0;
		}
	}
	/*for (int i = 1; i <= b; i++) {
		printf("%d ", sosu[i]);
	}*/
	for (int i = a; i <= b; i++) {
		if (sosu[i] != 0) {
			sum += sosu[i];
			if (chk) {
				res = sosu[i];
				chk = false;
			}
			//if (sosu[i] < res) { res = sosu[i]; }
		}
	}
	if (chk) printf("-1");
	else printf("%lld\n%d", sum, res);
}
