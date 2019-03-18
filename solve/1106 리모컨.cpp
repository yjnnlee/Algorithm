#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n, m, button, num[] = { 1,1,1,1,1,1,1,1,1,1}, len, maxres = 1e9, tmp;
char nn[500005];

int length(int num) {
	if (num == 0) return 1;
	int cnt = 0;
	while (num) {
		num /= 10;
		cnt++;
	}
	return cnt;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &button);
		num[button] = 0; //고장난 버튼 제거
	}
	sprintf(nn, "%d", n);
	len = strlen(nn);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j <= 9; j++) {
			if (num[j] == 0) continue;
			int click = abs(j - atoi(nn)); //+와 -를 몇 번 눌러야 가장 가까워지는지
			if (click < maxres) {
				maxres = click;
				tmp = i;
			}
		}

	}
}
