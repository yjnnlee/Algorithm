#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, w[10001], d[10001][2];
vector<int> v[10001], res;

void dpdfs(int now, int parent) {
	for (int i = 0; i < v[now].size(); i++) {
		if (v[now][i] == parent) continue;
		else dpdfs(v[now][i], now); //모든 경우에 대해 재귀를 보낸다
	}

	d[now][0] = 0;
	d[now][1] = w[now]; //1은 포함하는 경우이므로 가중치 더한다
	for (int i = 0; i < v[now].size(); i++) { //모든 자식들에 대해
		if (v[now][i] == parent) continue;
		
		d[now][0] += max(d[v[now][i]][0], d[v[now][i]][1]); //max(d[w_i][0], d[w_i][1])
		d[now][1] += d[v[now][i]][0]; //d[w_i][0] + w[now]
	}
}

void trace(int now, int isinclude, int parent) {
	if (isinclude == 1) { //포함인 경우
		res.push_back(now); //독립집합임
		for (int i = 0; i < v[now].size(); i++) {
			if (v[now][i] == parent) continue;
			trace(v[now][i], 0, now); //부모가 포함이면 자식들은 무조건 안 포함으로
		}	
	}
	else { //포함 아니면
		for (int i = 0; i < v[now].size(); i++) { //모든 자식들에 대해
			if (v[now][i] == parent) continue;

			if (d[v[now][i]][0] < d[v[now][i]][1]) {
				trace(v[now][i], 1, now); //자식도 포함이면
			}
			else trace(v[now][i], 0, now); //포함 아니면
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dpdfs(1, 0);
	cout << max(d[1][0], d[1][1]) << '\n';

	if (d[1][0] < d[1][1]) {
		trace(1, 1, 0); //포함이면
	}
	else {
		trace(1, 0, 0); //포함 아니면
	}

	sort(res.begin(), res.end());
	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i]<< " ";
	}
	return 0;
}
