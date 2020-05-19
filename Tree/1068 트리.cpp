#include <iostream>
#include <vector>
using namespace std;
int n, del, res = 0;
vector<vector<int>> tree;
int visit[100001];

void find(int now) {
	int childnode = 0;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (next == del) continue;
		find(next);
		childnode++;
	}
	if (!childnode) res++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int root;
	cin >> n;
	tree = vector<vector<int>>(n);
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		if (a != -1) tree[a].push_back(i);
		else root = i;
	}
	cin >> del;
	if (root == del) cout << "0";
	else {
		find(root);
		cout << res;
	}
}
