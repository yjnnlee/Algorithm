#include <stdio.h>
int n, res=-1, cnt=0, menu[100003], a;
int main() {
	scanf("%d", &n);
	n *= 2;
	while (n--) {
		scanf("%d", &a);
		if (menu[a] == 0) { //스티커가 없다면
			menu[a] = 1;
			cnt++;
			if (res < cnt) res = cnt;
		}
		else {
			if (res < cnt) res = cnt;
			cnt--;
			menu[a] = -1;
		}
	}
	printf("%d", res);
}
