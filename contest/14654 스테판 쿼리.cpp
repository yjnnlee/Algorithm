#include <stdio.h>
int n, a[305], b[305], cnt1 = 0, cnt2 = 0, p1 = 0, p2 = 0, res;

int battle(int x, int y) { //x가 이기면 0, y가 이기면 1
	if (x == 1 && y == 2) return 1;
	if (x == 1 && y == 3) return 0;
	if (x == 2 && y == 3) return 1;
	if (x == 2 && y == 1) return 0;
	if (x == 3 && y == 1) return 1;
	if (x == 3 && y == 2) return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) { //비기면
			if (!cnt1) {
				cnt1++; //p1가 이김
				if (res < cnt2) res = cnt2;
				cnt2 = 0;
			}
			else { //p2이 이김
				cnt2++;
				if (res < cnt1) res = cnt1;
				cnt1 = 0;
			}
			continue;
		}

		if (battle(a[i], b[i]) == 1) { //b[i]가 이기면
			cnt2++;
			if (res < cnt1) res = cnt1;
			cnt1 = 0;
		}
		else if (battle(a[i], b[i]) == 0) { //a[i]가 이기면
			cnt1++;
			if (res < cnt2) res = cnt2;
			cnt2 = 0;
		}
	}
	if (res < cnt2) res = cnt2;
	if (res < cnt1) res = cnt1;
	printf("%d", res);
}
