#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[21][21];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++) d[i] = i; //d배열에 1~n을 넣고 모든 순열을 돌리면 모든 인덱스 조합을 다 체크
	int res = 1e9;
	do {
		bool iszero = false; //0이 존재하는가? (올바른 경로인지 확인)
		int sum = 0; //경로의 비용
		for (int i = 0; i < n - 1; i++) { //마지막 도시 빼고 for문 돌면서
			if (a[d[i]][d[i + 1]] == 0) iszero = true; //올바른 경로가 아님
			else sum += a[d[i]][d[i + 1]]; //d[i]에서 d[i+1]로 가는 경로의 비용합
		}
		if (!iszero && a[d[n - 1]][d[0]] != 0) { //마지막 도시 n-1부터 첫도시 0까지의 경로가 0이 ㅇ아니면
			sum += a[d[n - 1]][d[0]]; //마지막~첫도시 경로 추가
			res = min(res, sum);
		}
	} while (next_permutation(d.begin(), d.end()));
	cout << res;
}
