#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <string>
#include <queue>
using namespace std;
int go[2000];
int v[2000][2000];
int visit[2000];
int n, k, a, b;
queue<pair<int,string>> q;
bool flag = false;
//void dfs(int now, string s) {
//	if (now == b) {
//		cout << s; flag = true;
//		return;
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			if (!visit[i] && v[now][i] == 1) {
//				visit[i] = 1;
//				dfs(i, s + to_string(i)+ " ");
//			}
//		}
//	}
//}

string bfs(int start, string s) {
	visit[start] = 1;
	q.push({ start,s });
	while (!q.empty()) {
		int now = q.front().first; 
		string nows = q.front().second;
		q.pop();
		if (now == b) {
			return nows;
			break;
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i] && v[now][i] == 1) {
				q.push({ i,nows + " " + to_string(i) });
				visit[i] = 1;
			}
		}
	}
	return "-1";
}

int main() {
	cin >> n >> k;
	vector<string> tmp;
	for (int i = 0; i < n; i++) {
		string tmps; cin >> tmps;
		tmp.push_back(tmps);
		//int sum = 0;
		//string tmp; cin >> tmp;
		//for (int j = 0; j < tmp.size(); j++) {
		//	sum += tmp[j] - '0'; //아예 더해버림
		//}
		//go[i] = sum;
	}
	//for (int i = 0; i < n; i++) {
	//	cout << go[i] << " ";
	//}
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//if (sqrt(go[i] - go[j]) == 1) { //해밍 경로이면
			//이렇게 하면 110->001 도 해밍 경로라고 해 버림;; 틀림
			int cnt = 0;
			for (int g = 0; g < k; g++) {
				if (tmp[i][g] != tmp[j][g]) {
					cnt++;
				}
			}
			if (cnt == 1) {
				v[i + 1][j + 1] = 1; //그래프 만들기
				v[j + 1][i + 1] = 1;
			}
		}
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << v[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout<<bfs(a, to_string(a));
	//이  문제를 bfs가 아닌 dfs로 짤 경우
	//전체탐색 하여 꼭 !!최소경로!!로 찾아야 함
	//해당 예시
	/*
5 3
000
001
010
011
111
1 3
답: 1 3
오답: 1 2 4 3
	*/
	
}
