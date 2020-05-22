#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int l = 0;

//start~end에서 left~right의 최대값 찾기
void update(vector<int> &tree, int i, int diff) {
	while (i <= l) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(vector<int>& tree, int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> tree(n + m + 1);
		vector<int> position(n + 1);
		l = n + m;
		for (int i = 1; i <= n; i++) {
			update(tree, m + i, 1); //m개를 띄워두고 1로 채운다
			position[i] = m + i; //빼려는 DVD의 위치를 알게 해주는 벡터
		}

		for (int i = m, x; i >= 1; i--) {
			cin >> x;
			cout << sum(tree, position[x] - 1)<<" "; //0~현재위치-1의 합
			update(tree, position[x], -1); //1이었던 곳에서 -1을 빼면 0이 된다
			position[x] = i; //현재 DVD의 위치를 앞으로 뺀다(여기서는 인덱스만 바꿈)
			update(tree, position[x], 1); //앞으로 뺀 DVD 위치에 1더한다(여기서 +1함)
		}
		cout << '\n';
	}
	return 0;
}
