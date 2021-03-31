#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int a, int b) {
	if (a > 0 && b > 0) return a > b; //양수면 내림차순
	else return b > a; //음수면 오름차순
	//큰 수가 앞으로 가게 한다
}
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), cmp);
	v.push_back(0);
	long long int res = 0;
	for (int i = 0; i < n; i++) {
		//cout << v[i] << " ";
		if (v[i] > 0) { //양수
			if (v[i+1] == 1) { //1이면 더하는 게 이득
				res += v[i] + v[i + 1];
				i++;
			}
			else if (v[i + 1] > 0 && i + 1 < n) { //양수+양수면 곱한다
				res += v[i] * v[i + 1];
				i++;
			}
			else {
				res += v[i]; //이도저도 아니면 더한다
			}
		}
		else if (v[i] == 0) {
			if (v[i + 1] < 0 && i + 1 < n) { //0과 음수면 곱한다
				i++;
			}
			else if (v[i + 1] == 0) continue;
			//음수가 아니면 0은 그냥 더한다(안 더한 것과 같음)
		}
		else if (v[i] < 0) { //음수+음수면 곱한다
			if (v[i + 1] < 0 && i + 1 < n) {
				res += v[i] * v[i + 1];
				i++;
			}
			else if (v[i + 1] == 0 && i + 1 < n) { //음수+0이면 곱한다
				res += v[i] * v[i + 1]; //곱해도 0이긴 하다
				i++; //근데 벡터 범위 때문에 0을 넣었기 때문에 끝의 0이면 곱하면x
			}
			else {
				res += v[i]; //아무것도 아니면 더한다
			}
		}
	}
	cout << res;
}
