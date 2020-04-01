#include <iostream>
using namespace std;
long long int arr[4000001];
int n, m;

long long sum(int s, int e) {
	long long res = 0;
	while (s <= e) {
		if (s % 2 == 1) res += arr[s];
		if (e % 2 == 0) res += arr[e];
		s = (s + 1) / 2; //부모 노드로 올라간다. 지금 있는 곳은 계산이 끝났기 때문에 오른쪽으로 이동
		e = (e - 1) / 2; //왼쪽 부모 노드로 올라간다
	}
	return res;
}

void update(int node, long long int val) {
	while (node > 0) {
		arr[node] += val;
		node /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int s = 1; //시작점 찾기, 여기서부터 거꾸로 배열이 채워질 것이다
	while (s < n) s *= 2; //세그먼트 트리 노드배열의 총개수=제곱했을 때 n을 넘는 가장 작은 어떤 수

	for (int i = 0; i < n; i++) {
		cin >> arr[i + s]; //리프 노드
	}
	for (int i = s - 1; i > 0; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];

	for (int i = 0, a, b, c, d; i < m; i++) {
		cin >> a >> b >> c >> d;
		if (a < b) cout << sum(a + s - 1, b + s - 1) << "\n";
		else if (a >= b)cout << sum(b + s - 1, a + s - 1) << "\n"; //같은 경우도 처리해줘야 함!!
		update(c + s - 1, d - arr[c + s - 1]);
	}
}
