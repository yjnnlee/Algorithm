#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n, m, k;

int sum(vector <ll> &tree,  int i) {
	int res = 0;
	while (i > 0) {
		res += tree[i];
		i -= i & -i; //i를 이진수로 했을 때 마지막 1의 위치 찾기
		//빼는 이유: 큰 수->작은 수로 내려오면서 범위를 찾기 때문임
	}
	return res;
}

void update(vector<ll> &tree, int i, int num) {
	while (i <= tree.size()) {
		tree[i] += num;
		i += i & -i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	while (k--) {
		vector<ll> tree(200002);
		vector<ll> arr(200002);
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			arr[i] = n - i + 1; //책은 거꾸로 쌓여 있다
			update(tree, i, 1);
		}
		
		for (int i = 1, a; i <= m; i++) {
			cin >> a;
			cout << sum(tree, 200001) - sum(tree, arr[a])<<" "; //모든 dvd-자기 아래 dvd=자기 위의 dvd
			update(tree, arr[a], -1); //원래 위치에서 dvd를 뽑아서
			arr[a] = n + i; //꼭대기에다가 쌓는다
			update(tree, arr[a], 1);  //새로 쌓인 위치를 1로 바꾼다

			//for (int q = 1; q <= n + m; q++) cout << arr[q] << " ";
			//cout << endl;
		}
		cout << "\n";
	}
}


