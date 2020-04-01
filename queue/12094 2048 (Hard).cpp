#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
int n, map[21][21], res = 0, chk[11];

int maxvaluefind() {
	int maxres = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > maxres) maxres = map[i][j];
		}
	}
	return maxres;
}

bool chkmap(int orimap[][21], int movemap[][21]) {
	//상하좌우로 움직인 후가 이전의 map과 완전히 같다면 넘어간다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (movemap[i][j] != orimap[i][j]) return false; //같지 않다면 false
		}
	}
	return true;
}

void mapMove(int what) {
	queue<int> q;

	if (what == 0) { //left
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j]) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			}
			int j = 0;
			while (!q.empty()) {
				int next = q.front();
				q.pop();

				//숫자가 0이면 아무 값도 없는 것이기 때문에 넣어준다
				if (map[i][j] == 0) map[i][j] = next;
				else if (map[i][j] == next) { //숫자가 같으면 합치고 이동
					map[i][j++] += next;
				}
				else if (map[i][j]) { //숫자가 있긴 한데 다른 값이면 이동하고 값 넣음
					map[i][++j] = next;
				}
			}
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
			int j = n - 1;
			while (!q.empty()) {
				int next = q.front();
				q.pop();

				//숫자가 0이면 아무 값도 없는 것이기 때문에 넣어준다
				if (map[i][j] == 0) map[i][j] = next;
				else if (map[i][j] == next) { //숫자가 같으면 합치고 이동
					map[i][j--] = next * 2;
				}
				else if (map[i][j]) { //숫자가 있긴 한데 다른 값이면 이동하고 값 넣음
					map[i][--j] = next;
				}
			}
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
			int j = 0;
			while (!q.empty()) {
				int next = q.front();
				q.pop();

				//숫자가 0이면 아무 값도 없는 것이기 때문에 넣어준다
				if (map[j][i] == 0) map[j][i] = next;
				else if (map[j][i] == next) { //숫자가 같으면 합치고 이동
					map[j++][i] += next;
				}
				else if (map[j][i]) { //숫자가 있긴 한데 다른 값이면 이동하고 값 넣음
					map[++j][i] = next;
				}
			}
		}
	}
	else if (what == 3) { //down
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if(map[j][i]) {
					q.push(map[j][i]);
					map[j][i] = 0;
				}
			}
			int j = n - 1;
			while (!q.empty()) {
				int next = q.front();
				q.pop();

				//숫자가 0이면 아무 값도 없는 것이기 때문에 넣어준다
				if (map[j][i] == 0) map[j][i] = next;
				else if (map[j][i] == next) { //숫자가 같으면 합치고 이동
					map[j--][i] += next;
				}
				else if (map[j][i]) { //숫자가 있긴 한데 다른 값이면 이동하고 값 넣음
					map[--j][i] = next;
				}
			}
		}
	}
}

void copymap(int a[][21], int b[][21]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = b[i][j];
		}
	}
}

//bool isPossible(int nextMax, int nextCnt) { //시간 줄이기2: 현재 cnt보다 더 간다 해도 최대값을 못 만드는 경우라면 빠른 포기
//	int remainCnt = 10 - nextCnt;
//	int expectMax = nextMax * pow(2, remainCnt);
//	//현재 숫자가 될 수 있는 가장 큰 수는 현재수*(2^남은수)
//	if (expectMax <= res) return false; //될 수 없다
//	else return true;
//}

void solve(int cnt) { //dfs	
	int maxres = maxvaluefind();
	if (maxres <= chk[cnt]) return; //현재 cnt값에서 최대값을 만드는 게 불가능하면 패스

	if (cnt == 10) {
		res = max(res, maxres);
		int val = res;
		while (cnt > 0) {
			chk[cnt--] = val;
			val /= 2;
		}
		return;
	}
	int originalmap[21][21] = { 0, }; //이거 왜 전역변수면 딴 값이 나오지? hm...
	copymap(originalmap, map); //originalmap: 원래 맵을 map: 바뀔 맵에 복사
	//시간 줄이기3: memcpy 시간을 줄여야 한다

	for (int j = 0; j < 4; j++) {
		mapMove(j);
		if (chkmap(originalmap, map)) continue; //시간 줄이기1: 이동한 맵이 그 전 맵과 같으면 더이상 움직일 필요 없다
		else {
			solve(cnt + 1);
			copymap(map, originalmap); //원래 맵으로 돌린다
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	res = maxvaluefind();
	//만약 한 번도 움직이지 못하는 보드의 경우 갱신되지 않으니까 여기서 해준다
	solve(0);
	cout << res;

	return 0;
}

/*
3
256 8 128
16 0 256
0 8 0

512
*/
