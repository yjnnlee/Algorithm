#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int sum(vector <ll>& tree, int i) {
	int res = 0;
	while (i > 0) {
		res += tree[i];
		i -= i & -i; //i를 이진수로 했을 때 마지막 1의 위치 찾기
		//빼는 이유: 큰 수->작은 수로 내려오면서 범위를 찾기 때문임
	}
	return res;
}

void update(vector<ll>& tree, int i, int num) {
	while (i <= tree.size()) {
		tree[i] += num;
		i += i & -i;
	}
}

int main() {
	/*
	수평선을 놓는다고 생각하면 됨
	양 끝 값을 제외한 유효한 곳에 수평선을 놓고(그 길이 부분은 1이 됨)
	a,b입력 받아서 해당 위치의 값을 출력하고 0으로 바꿈
	왜 a, b부분만 하냐면 그 전 수평선과 겹쳐질 수 있는 부분은 a/b의 아래로 향하는 직선 뿐이기 때문
	a, b부분을 0으로 하는 이유는 꽃을 이미 셌기 때문

	세그트리: 수평선이 존재하는 위치

	*/
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, b, aa, bb;
	vector<ll> tree(200001);
	cin >> n;

	while (n--) {
		cin >> a >> b;
		aa = sum(tree, a); //a에서 y=0까지 쭉 선분을 내렸을 때 겹쳐지는 수평선의 합
		bb = sum(tree, b);

		cout << aa + bb << '\n'; //a와 b부분의 수평선 겹친 수의 합을 출력

		update(tree, a, -aa); //a부터 끝까지 -aa가 된다
		update(tree, a + 1, aa); // a+1부터 끝까지 aa가 된다
		//즉 a만 -aa로 남는다
		//a에는 원래 aa가 있었으므로 -aa를 하면 0이 된다(=꽃 출력하고 0으로)

		update(tree, b, -bb);
		update(tree, b + 1, bb);

		update(tree, a + 1, 1);
		update(tree, b, -1);
		//a+1~b-1구간에다가 1을 더해서 수평선을 놓는다
	}
}
