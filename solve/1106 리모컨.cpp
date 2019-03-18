#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n, m, button, num[] = { 1,1,1,1,1,1,1,1,1,1}, len;
char nn[500005];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &button);
		num[button] = 0; //고장난 버튼 제거
	}
	sprintf(nn, "%d", n);
	len = strlen(nn);
	for (int i = 0; i < len; i++) {
		int min = 0; //제일 가까운 수
		for (int j = 0; j <= 9; j++) {
			if (num[j] == 0) continue;
			if (abs(j - atoi(nn)) < min) min = j;
		}
	}
}
