#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, h;
bool map[31][11];
int res = 1e9;

bool chk_game() {
	for (int i = 1;i <= n;i++) {
		int now = i; //row
		for (int j = 0;j < h;j++) { //모든 높이에서 사다리 설치해 봄
			if (map[j][now]) {
				//오른쪽으로
				now += 1;
			}
			else if (map[j][now - 1]) {
				//왼쪽으로
				now -= 1;
			}
		}
		if (now != i) return false; //i가 아니면 이건 아님
	}
	return true; //찾음
}

void go(int y, int cnt) {
	if (cnt >= 4) return; //추가된 가로선 3개 넘으면 -1
	if (chk_game()) {
		res = min(res, cnt);
		return;
	}
	for (int i = y; i <= h;i++) {
		for (int j = 1;j < n;j++) {
			//가로선이 연속하거나 접하면 안 된다
			if (!map[i][j] && !map[i][j - 1] && !map[i][j + 1]) {
				map[i][j] = true;
				go(i, cnt+1);
				map[i][j] = false; //백트래킹
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie();
	cin >> n >> m >> h;
	for (int i = 0;i < m;i++) {
		int y, x;
		cin >> y >> x;
		map[y - 1][x] = true; //y-1번째 col에서 x~x+1을 잇는 사다리
	}
	
	go(0, 0);
	if (res == 1e9) cout << -1;
	else cout << res;
}
