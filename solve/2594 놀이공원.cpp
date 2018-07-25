#include <stdio.h>
#include <algorithm>
using namespace std;

int n, x, y;

struct S {
	int start, end;
};

bool cmp(const S &one, const S &two) {
	if (one.start == two.start) {
		return one.end < two.end;
	}
	else return one.start < two.start;
}

int main() {
	scanf("%d", &n);
	S a[53];
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		a[i].start = (x / 100 * 60) + (x % 100) - 10; //분 단위로 변환 + 쉬는 시간 계산
		a[i].end = (y / 100 * 60) + (y % 100) + 10;
	}
	sort(a, a + n, cmp);

	/*for (int i = 1; i <= n; i++) {
		printf("%d %d\n", a[i].start, a[i].end);
	}*/
	int s = 600, e = 600, res = 0;
	for (int i = 0; i < n; i++) {
		/*if (i == 1 && start != 600) {
			res = max(res, s[1].start - 600); 아래 포함됨
		}*/

		if (a[i].start > e) { //시작 시간이 마지막 종료시간보다 크면 휴식이 생김
			if (a[i].start - e > res) res = a[i].start - e;
			if (a[i].end > e) e = a[i].end;
			s = a[i].start;
		}
		else {
			if (a[i].end > e) e = a[i].end;
		}

		if (i == n - 1 && e != (22 * 60)) res = max(res, 22 * 60 - e);
	}
	printf("%d", res);
}
