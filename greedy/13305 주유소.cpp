#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
long long int len[100001], oil[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> len[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> oil[i];
	}
	long long int res = 0;
	int a = oil[0]; //맨 처음은 무조건 살 것이다
	for (int i = 0; i < n; i++) {
		if (a > oil[i]) a = oil[i]; //더 적은 가격이 나오면 갱신
		res += len[i] * a; //현재보다 적은 가격이 나오기 전까지 계속 산다
	}
	cout << res;
}
