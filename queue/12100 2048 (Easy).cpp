#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory.h>
#include <queue>	
using namespace std;
int n, map[21][21], res = 0;
queue<int> q;

void merge(int i, int j, int di, int dj) {
	while (!q.empty()) {
		int next = q.front();
		q.pop();

		//숫자가 0이면 아무 값도 없는 것이기 때문에 넣어준다
		if (map[i][j] == 0) map[i][j] = next;
		else if (map[i][j] == next) { //숫자가 같으면 합친다
			map[i][j] = next * 2;
			i += di, j += dj;
		}
		else { //숫자가 있긴 한데 다른 값이면 그 다음 칸에 넣어준다
			i += di, j += dj;
			map[i][j] = next;
		}
	}
}

void move(int what) {
	if (what == 0) { //left
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j]) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			}
			merge(i, 0, 0, 1);
		}
	}
	else if (what == 1) { //right
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j]) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			}
			merge(i, n - 1, 0, -1);
		}
	}
	if (what == 2) { //up
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[j][i]) {
					q.push(map[j][i]);
					map[j][i] = 0;
				}
			}
			merge(0, i, 1, 0);
		}
	}
	else if (what == 3) { //down
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (map[j][i]) {
					q.push(map[j][i]);
					map[j][i] = 0;
				}
			}
			merge(n - 1, i, -1, 0);
		}
	}
}

void solve(int cnt) {
	//1. 위 아래 오른쪽 왼쪽으로 돌려본다
	//2. 그 중 가장 큰 수를 res값으로 갱신
	//3. 그 중 가장 큰 수의 보드 상태를 다음 라운드로 넘긴다

	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > res) res = map[i][j];
			}
		}
		return;
	}
	int tmpmap[21][21];
	memcpy(tmpmap, map, sizeof(map)); //tmpmap: 원래 맵, map: 바뀐 맵
	for (int j = 0; j < 4; j++) {
		move(j);
		solve(cnt + 1);
		memcpy(map, tmpmap, sizeof(tmpmap)); //원래 맵으로 돌린다
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve(0);
	cout << res;
}
