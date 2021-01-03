#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int a[51][51], want[51][51];
int n, m;

void flip(int y, int x) { //3x3 flip
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) {
			a[i][j] = 1 - a[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			a[i][j] = c - 48; //c++에서는 정수 한 자리씩 받기가 안 돼서 char형 받고 int로 넣는다
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			want[i][j] = c - 48;
		}
	}
	int res = 0;
	for (int i = 0; i < n-2; i++) { //왼쪽 맨 위부터 한 줄 씩 맞춘다
		for (int j = 0; j < m-2; j++) {
			if (a[i][j] != want[i][j]) { //맞지 않으면 뒤집어서 맞춘다
				res++;
				flip(i+1, j+1); //0부터 시작하는 인덱스를 1부터 시작하게 맞춘다
			}
		}
	}

	for (int i = 0; i < n; i++) { //맞지 않는지 검사
		for (int j = 0; j < m; j++) {
			if (a[i][j] != want[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << res;
}
