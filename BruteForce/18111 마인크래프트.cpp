#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int map[501][501];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, b;
	cin >> n >> m >> b;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//망한 접근
	//int base = max_element(chk.begin(), chk.end()) - chk.begin(); //가장 많이 나온 수의 인덱스. 이것을 기준으로 컷or더함

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		if (map[i][j] != base) {
	//			if (map[i][j] > base) { //블럭이 base보다 많으면 컷

	//			}
	//			else if (map[i][j] < base) { //블럭이 base보다 적으면 더함
	//				//근데 이 경우에 더할 블록이 없으면?
	//				//base가 바뀌어야 하는데 그러면 int base부터 다시 구해야?
	//				//이건 아닌 듯..
	//			}
	//		}
	//	}
	//}

	//접근2
	//범위가 작음->브루트포스->h의 범위는 0~256이므로 다 돌려본다
	int restime = 1e9, resh = 0;
	for (int h = 0; h <= 256; h++) {
		int add = 0, del = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int hh = map[i][j] - h;
				if (hh > 0) del += hh; //기준보다 높다면 제거
				else if (hh < 0) add -= hh; //기준보다 낮다면 추가 (가진 블록에서 빼야되니까 이미 뺌)
			}
		}
		if (del + b >= add) { //가진 블록+제거 블록>=추가해야 하는 블록 수 여야 함. 추가해야 하는 블록만큼을 최소한으로 가지고 있어야 평평하게 할 수 있다
			int time = del * 2 + add;
			if (restime >= time) { //더 좋은 결과라면 갱신
				//시간이 같은 경우 더 큰 수 출력 조건있으서 >=
				restime = time;
				resh = h;
			}

		}
	}
	cout << restime << " " << resh;
}
