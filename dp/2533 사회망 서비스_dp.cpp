#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, d[1000001][2];
bool chk[1000001];
vector<int> v[1000001];

void dfs(int now) {
	chk[now] = true; //방문했다고 체크한다
	d[now][0] = 0;
	d[now][1] = 1;
	for (int i = 0; i < v[now].size(); i++) { //모든 자식들에 대해
		if (chk[v[now][i]]) continue; //i를 방문한 적이 있다=부모를 의미하니까 패스
		dfs(v[now][i]);
		d[now][0] += d[v[now][i]][1]; //부모가 포함되지 않으면 자식은 포함이 되어야 함
		d[now][1] += min(d[v[now][i]][0], d[v[now][i]][1]); //부모가 포함되었으면 자식은 포함/안 포함 중에 작은 값
	}
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << min(d[1][0], d[1][1]);
	return 0;
}
