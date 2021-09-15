#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> map(9), tmpmap(9);

bool go(vector<int> &a) {
	//행열이 모두 같아야 한다
	int sum = a[0] + a[1] + a[2];
	//int sum = a[0][0] + a[0][1] + a[0][2]; //기준
	
	//행
	//if (a[1][0] + a[1][1] + a[1][2] != sum) return false;
	if (a[3] + a[4] + a[5] != sum) return false;
	//if (a[2][0] + a[2][1] + a[2][2] != sum) return false;
	if (a[6] + a[7] + a[8] != sum) return false;

	//열
	//if (a[0][0] + a[1][0] + a[2][0] != sum) return false;
	if (a[0] + a[3] + a[6] != sum) return false;
	//if (a[0][1] + a[1][1] + a[2][1] != sum) return false;
	if (a[1] + a[4] + a[7] != sum) return false;
	//if (a[0][2] + a[1][2] + a[2][2] != sum) return false;
	if (a[2] + a[5] + a[8] != sum) return false;

	//대각선
	//if (a[0][0] + a[1][1] + a[2][2] != sum) return false;
	if (a[0] + a[4] + a[8] != sum) return false;
	//if (a[0][2] + a[1][1] + a[2][0] != sum) return false;
	if (a[2] + a[4] + a[6] != sum) return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie();
	for (int i = 0;i < 9;i++) {
		cin >> map[i];
	}

	for (int i = 0;i < 9;i++) {
		tmpmap[i] = i + 1;
	}

	//크기가 3x3인 매직 스퀘어는 1부터 9까지 수가 한 번씩 등장해야 한다
	//모든 경우의 수를 넣어서 가능한지 본다

	int res = -1;
	do {
		if (go(tmpmap)) {
			int diff = 0;
			for (int i = 0;i < 9;i++) {
				diff += abs(map[i] - tmpmap[i]);
			}
			
			if (res == -1 || res > diff) {
				res = diff;
			}
		}
	} while (next_permutation(tmpmap.begin(), tmpmap.end()));

	cout << res;
}
