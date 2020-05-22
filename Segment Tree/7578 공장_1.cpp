#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int l;

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

int sum(vector<int> &tree, int l, int r) {
	if (l > r) return 0;
	return sum(tree, r) - sum(tree, l - 1);
	/*l-1을 하는 이유: 만약 2~5인덱스를 더해야 할 때
	메인에서 +1로 넘어왔기 때문에 2~5자체를 가리키고 있는데
	(1~5)-(1~1)을 해야 2~5가 나오기 때문에 l쪽은 자기 자신을 빼줘야 함
	*/
}

const int MAX = 5000000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	map<int, int> position;
	for (int i = 0, num; i < n; i++) {
		cin >> num;
		position[num] = i + 1; //<num, i+1>
	}
	
	long long ans = 0;
	vector<int> tree(n + 1);
	l = n;
	for (int i = 0; i < n; i++) {
		ans += (long long)sum(tree, position[a[i]] + 1, n);
		update(tree, position[a[i]], 1);
	}
	cout << ans;
	return 0;
}
