#include <stdio.h>
int n, now = 1, sw = 0, bsw = 0; //sw - 5명이 0, 1명이 1
char a[100];
int main() {
	scanf("%d", &n);
	scanf("%s", a);
	for (int i = 0; i < n; i++) {
//		printf(">%d %d %d\n", now, sw, bsw);
		if (now >= 3) {
			break;
		}
		if (a[i] == 'W') {
			now++;
		}
		else if (a[i] == 'P') {
			if (now == 2) {
				bsw = 1; //B에서 레버를 당겼다면 C일때 6명
			}

			if (sw == 0) {
				sw = 1;
			}
			else sw = 0;
		}
	}
	if (bsw == 1 && now >= 3) { //레버가 당겨졌는데 끝까지 왔으면 6명
		printf("6");
		return 0;
	}
	if (now < 3) { //C에 도착하지 않으면 0
		printf("0");
		return 0;
	}
	if (sw == 1) printf("1");
	else printf("5");
}
