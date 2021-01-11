#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

int a[300001], b[300001];
bool cmp(const int& a, const int& b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i =0; i < n; i++) {
		cin >> a[i];
	}
	int res = 0, index = 0;
	for (int i = 0; i < n-1; i++) {
		b[i] =  a[i + 1] - a[i]; //인접끼리의 차이를 구한다
	}
	sort(b, b + n, cmp); //내림차순
	for (int i = 0; i <= n; i++) {
		cout << b[i] << " ";
	}
	for (int i = k-1; i <n-1; i++) { //차가 가장 큰 k-1개는 버리고 k~끝까지 더한다
		res += b[i];
	}
//	cout << endl;
	cout << res;
}
