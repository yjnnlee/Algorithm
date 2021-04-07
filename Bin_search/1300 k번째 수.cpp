#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
 
int bin(){
	int l = 0, r = m, mid, res; //m을 넘어갈 수 없음
	while (l <= r) {
		mid = (l + r) / 2;
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt < m) l = mid + 1;
		else r = mid - 1, res = mid;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	//for (int i = 1; i <= n; i++) { 이거 하면 메모리초과
	//	for (int j = 1; j <= n; j++) {
	//		v.push_back(i * j);
	//	}
	//}
	//sort(v.begin(), v.end());
	cout << bin();
}
