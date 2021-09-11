#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int a[20][20];
long long go(int y, int x, int dir) {
	if (x == n - 1 && y == n - 1) {
		return 1;
	}
	long long res = 0;
	if (dir == 0) { //가로면
		if (a[y][x + 1] == 0 && x + 1 < n) { //가로
			res += go(y, x + 1, 0);
		}
		if (y + 1 < n && x + 1 < n && a[y][x + 1] == 0 && a[y + 1][x + 1] == 0 && a[y + 1][x] == 0) {
			res += go(y + 1, x + 1, 1); //대각선
		}
	}
	else if (dir == 1) { //대각선이면
		if (a[y][x + 1] == 0 && x + 1 < n) { //가로
			res += go(y, x + 1, 0);
		}
		if (y + 1 < n && a[y + 1][x] == 0) { //세로
			res += go(y + 1, x, 2);
		}
		if (y + 1 < n && x + 1 < n && a[y][x + 1] == 0 && a[y + 1][x + 1] == 0 && a[y + 1][x] == 0) {
			res += go(y + 1, x + 1, 1); //대각선
		}
	}
	else if (dir == 2) { //세로면
		if (y + 1 < n && a[y + 1][x] == 0) { //세로
			res += go(y + 1, x, 2);
		}
		if (y + 1 < n && x + 1 < n && a[y][x + 1] == 0 && a[y + 1][x + 1] == 0 && a[y + 1][x] == 0) {
			res += go(y + 1, x + 1, 1); //대각선
		}
	}
	return res;
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}
	cout << go(0, 1, 0); //세로, 가로, 진행 방향(0가로, 1대각, 2세로)
	//0,0과 0,1가 첫 위치니까 끝 값인 0,1만 넣고 시작
}
