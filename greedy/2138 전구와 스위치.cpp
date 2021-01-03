#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int a[100001], b[100001], want[100001];
int n, res = 100001;

void go(int a[], int now, int cnt) {
	if (now == n - 1) { //마지막엔 누른다, 안 누른다 두 경우에 대해 최종 상태가 되는지 확인
		if (a[now - 1] == want[now - 1] && a[now] == want[now]) { //안 누른 경우
			res = min(res, cnt);
		}
		for (int i = now - 1; i <= now + 1; i++) { //누른 경우 주변 3개 바꾼다
			a[i] = 1 - a[i];
		}
		if (a[now - 1] == want[now - 1] && a[now] == want[now]) { //누른 경우
			res = min(res, cnt + 1);
		}
		return;
	}

	if (a[now - 1] == want[now - 1]) { //스위치를 안 누른 경우 두 값은 같다
		go(a, now + 1, cnt);
	}
	for (int i = now - 1; i <= now + 1; i++) { //스위치를 누른 경우 3개를 바꾼다
		a[i] = 1 - a[i];
	}
	if (a[now - 1] == want[now - 1]) { //스위치를 눌렀는데 같아지면 다음으로
		go(a, now + 1, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0'; //(char)c - 48을 이렇게 string으로도 가능
		b[i] = s[i] - '0';
	}
	cin >> s;
	for (int i = 0; i < n; i++) {
		want[i] = s[i] - '0';
	}
	b[0] = 1 - b[0];
	b[1] = 1 - b[1]; //0번 스위치를 누른 경우

	go(a, 1, 0); //0번 스위치를 안 누른다
	go(b, 1, 1); //0번 스위치를 누른다

	if (res == 100001) cout << -1;
	else cout << res;
}
