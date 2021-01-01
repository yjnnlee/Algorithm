#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int n;
struct Node {
	int len, index;
};
vector<Node> tree[100001];
int visit[100001];
int maxLen = 0, maxNode = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			tree[a].push_back({ b, 1 }); //거리는 1
			tree[b].push_back({ a, 1 });
		}
		cout << n - 1<<"\n"; //비행기의 종류ㅡㅡ..
	}
}
