#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
int r, c, max_virus, queries; //queries=쿼리의 개수
vector<pair<int,int>> q;
int map[103][103];
int chk[103][103];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void go(int y, int x) {
	chk[y][x] = 1;
	if (map[y][x] < max_virus) map[y][x]++;
	else {
		for (int i = 0;i < 4;i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 1 && yy <= r && xx >= 1 && xx <= c) {
				if (map[yy][xx] <= max_virus && !chk[yy][xx]) {
					go(yy, xx);
				}
			}
		}
	}
	return;
}

int main() {
	cin >> r >> c >> max_virus >> queries;
	for (int i = 0;i < queries;i++) {
		int a, b; cin >> a >> b;
		q.push_back({ a,b });
	}

	for (int i = 0;i < queries;i++) {
		memset(chk, 0, sizeof(chk));
		go(q[i].first, q[i].second);
	}

	for (int i = 1;i <= r;i++) {
		for (int j = 1;j <= c;j++) {
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
}

/*
input
3
4
2
8
3 2
3 2
2 2
3 2
1 4
3 2
2 3
3 1
output
0 2 1 1
2 2 2 1
2 2 2 1

time-00:10:02
*/
