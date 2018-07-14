#include <stdio.h>
int n, m, chk[1005][1005];
char a[1005][1005];
int c = 1, res = 0, y, x;
void f(int i, int j) {
	y = i, x = j;
	if (chk[y][x]) return;

	chk[y][x] = c;
	if (a[y][x] == 'S') return f(y + 1, x);
	else if (a[y][x] == 'N') return f(y - 1, x);
	else if (a[y][x] == 'W') return f(y, x - 1);
	else if (a[y][x] == 'E') return f(y, x + 1);
}

void ff(int i, int j) {
	y = i, x = j;
	while (!chk[y][x]) {
		chk[y][x] = c;
		if (a[y][x] == 'S') y++;
		else if (a[y][x] == 'N') y--;
		else if (a[y][x] == 'W') x--;
		else if (a[y][x] == 'E') x++;
	}
}
//void p() {
//	printf("\n");
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			printf("%d ", chk[i][j]);
//		}
//		printf("\n");
//	}
//}
int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", &a[i]);
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j]) continue;
			f(i, j);
			//ff(i,j); 도 가능

			res += chk[y][x] == c++; //이것의 의미는
			//res += (chk[y][x] == c++); 과 같고
			/*if (chk[i][j] == c) {
				res++;
			}
			c++; 랑 같다
			우변부터 계산해서 참이면 1이라 1더해줌
			*/
		}
	}
	printf("%d", res);
}
