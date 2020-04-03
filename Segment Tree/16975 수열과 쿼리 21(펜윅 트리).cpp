#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n, m;

ll sum(vector <ll> &tree, int i) {
	ll res = 0;
	while (i > 0) {
		res += tree[i];
		i -= i & -i; //i를 이진수로 했을 때 마지막 1의 위치 찾기
	}
	return res;
}

void update(vector<ll> &tree, int i, ll num) {
	while (i < tree.size()) {
		tree[i] += num;
		i += i & -i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<ll> tree(200001);

	cin >> n;
	for (int i = 1, t, prv = 0; i <= n; i++) { //여기 0부터 시작하면 while에서 무한루프 돈다
		cin >> t;
		update(tree, i, t - prv);
		prv = t;
	}
	//for (int i = 0; i < 20; i++) {
	//	cout << tree[i] << " ";
	//}
	//cout << endl;

	cin >> m;
	while (m--) {
		int a, b, c, d;
		cin >> a >> b;
		if (a == 1) {
			cin >> c >> d;
			update(tree, b, d);
			update(tree, c + 1, -d);
		}
		else {
			cout << sum(tree, b) << "\n";
		}

		//for (int i = 0; i < 20; i++) {
		//	cout << tree[i] << " ";
		//}
		//cout << endl;
	}
}
//https://www.acmicpc.net/blog/view/88
//https://m.blog.naver.com/PostView.nhn?blogId=jh05013&logNo=221475142152&proxyReferer=https%3A%2F%2Fwww.google.com%2F
//https://www.acmicpc.net/blog/view/88
