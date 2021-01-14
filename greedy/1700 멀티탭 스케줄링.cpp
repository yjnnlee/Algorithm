#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int a[101], pluged[101];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	int res = 0;
	for (int i = 0; i < k; i++) { //모든 전기용품에 대해서
		bool use = false;
		for (int j = 0; j < n; j++) { //1. 이미 꽂혀 있나?
			if (a[i] == pluged[j]) {
				use = true;
				break;
			}
		}
		if (use) continue; //꽂혀 있으면 그냥 냅둔다

		use = false;
		for (int j = 0; j < n; j++) { //2. 플러그 구멍이 남았나?
			if (pluged[j] == 0) {
				pluged[j] = a[i];
				use = true;
				break;
			}
		}
		if (use) continue; //구멍이 남으면 딴 거 뽑을 필요 없음

		//3. 다른 걸 뽑아야 할 때->가장 나중에 다시 나오는 전기용품을 뽑음
		int swap_num = -1, swap_index = -1;
		for (int j = 0; j < n; j++) {
			int next = 0;
			for (int q = i + 1; q < k && a[q] != pluged[j]; q++) { //다음 나올 때를 찾음
				next++;
			}
			if (swap_num < next) {
				swap_index = j;
				swap_num = next;
			}
		}
		res++;
		pluged[swap_index] = a[i]; //바꿔낌
	}
	cout << res;
}
