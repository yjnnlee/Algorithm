#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, d[1000001][2];
bool chk[1000001];
vector<int> v[1000001];

int dfs(int now, int isinclude) {
	int &res = d[now][isinclude];
	//cout << res << endl;
	if (res != -1) return res;
	chk[now] = true; //방문했다고 체크한다
	res = isinclude;

	//for (int next = 0; next < v[now].size(); next++) { //모든 자식들에 대해
	//	if (chk[v[now][next]]) continue; //next를 방문한 적이 있다=부모를 의미하니까 패스
	//	if (isinclude == 0) res += dfs(v[now][next], 1); //부모가 포함되지 않으면 자식은 포함이 되어야 함
	//	else res += min(dfs(v[now][next], 0), dfs(v[now][next], 1)); //부모가 포함되었으면 자식은 포함/안 포함 중에 작은 값
	//}
//	for (int next = 0; next < v[now].size(); next++) { //모든 자식들에 대해
	for (int next : v[now]) { //이렇게도 된다
		if (chk[next]) continue; //next를 방문한 적이 있다=부모를 의미하니까 패스
		if (isinclude == 0) res += dfs(next, 1); //부모가 포함되지 않으면 자식은 포함이 되어야 함
		else res += min(dfs(next, 0), dfs(next, 1)); //부모가 포함되었으면 자식은 포함/안 포함 중에 작은 값
	}
	chk[now] = false; //포함/안 포함 경우 때문에 최대 2번 다시 방문할 수도 있으니 체크를 풀어준다
	return res;
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(d, -1, sizeof(d));
	cout << min(dfs(1, 0), dfs(1, 1));
	return 0;
}
