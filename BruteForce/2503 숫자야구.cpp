#include <iostream>
#include <string>
using namespace std;
int n, num[101], strike[101], ball[101], scnt = 0, bcnt = 0, res = 0;
string strn, strnum;
bool isres;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i] >> strike[i] >> ball[i];
	}

	for (int i = 123; i < 999; i++) {
		strn = to_string(i);
		isres = true;
		if (strn[0] == strn[1] || strn[0] == strn[2] || strn[1] == strn[2] ||
			strn[0] == '0' || strn[1] == '0' || strn[2] == '0') continue;
		//각 자리의 숫자가 달라야 함, 숫자 범위는 1~9까지

		for (int k = 0; k < n; k++) {
			strnum = to_string(num[k]);
			scnt = 0, bcnt = 0;

			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					if (x == y && strn[x] == strnum[y]) scnt++; //자리 숫자 같으면 스트라이크
					if (x != y && strn[x] == strnum[y]) bcnt++; //숫자만 같으면 볼
				}
			}
			if (strike[k] != scnt || ball[k] != bcnt) {
				isres = false;
				break; //질문 중 하나라도 통과하지 못했다면 더 볼 필요 없음
			}
		}
		if (isres) {
			res++;
			//cout << strn<<endl;
		}
	}
	cout << res;
}
