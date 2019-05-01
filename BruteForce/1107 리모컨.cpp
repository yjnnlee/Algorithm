#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, a[10] = { 0,1,2,3,4,5,6,7,8,9 }, tmp, res = 0, res2 = 0;

int f(int n) { //리모컨으로만 누를 수 있는 번호의 길이 찾기
	int len = 0;
	if (n == 0) {
		if (a[0] == -1) return 0;
		else return 1;
	}

	while (n > 0) {
		if (a[n % 10] == -1) return 0;
		else {
			n /= 10;
			len++;
		}
	}
	return len;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &tmp);
		a[tmp] = -1;
	}
	
	res2 = abs(n - 100); //+, -로만 가는 경우
	for (int i = 0; i <= 999999; i++) {
		int lenth = f(i);
		if (lenth > 0) {
			res = abs(n - i) + lenth; 
			//버튼으로 누를 수 있는 경우와 +,-로만 가는 경우 합산
			if (res2 > res) res2 = res; //그렇게 누르는 것이 +,-로만 가는 것보다 적으면 바꿈
		}
	}
	printf("%d", res2);
}

/*
반례들
0 0이면 1

https://www.acmicpc.net/board/view/31853

9
8
0 3 4 5 6 7 8 9
답 4

*/
