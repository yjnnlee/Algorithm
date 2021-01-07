#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, s, r;
	cin >> n >> s >> r;
	int kayak[11];
	for (int i = 1; i <= n; i++) {
		kayak[i] = 1;
	}
	int broken[11], extra[11], res = 0;
	for (int i = 0; i < s; i++) {
		cin >> broken[i];
		kayak[broken[i]]--;
	}
	for (int i = 0; i < r; i++) {
		cin >> extra[i];
		kayak[extra[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (kayak[i] == 0) {
			if (i == 0 && kayak[i + 1] > 1) { //맨 앞의 팀은 그 다음 팀한테밖에 못 빌림
				kayak[i + 1]--;
				kayak[i]++;
			}
			else if (i == n && kayak[i - 1] > 1) { //맨 뒷 팀은 그 앞 팀한테밖에 못 빌림
				kayak[i - 1]--;
				kayak[i]++;
			}
			else { //중간팀이면 양쪽 확인
				if (kayak[i - 1] > 1) {
					kayak[i - 1]--;
					kayak[i]++;
				}
				else if (kayak[i + 1] > 1) {
					kayak[i + 1]--;
					kayak[i]++;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		//cout << kayak[i] << " ";
		if (kayak[i] == 0) res++;
	}
	cout << res;
}
