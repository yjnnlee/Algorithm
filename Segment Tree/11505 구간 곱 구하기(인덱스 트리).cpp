#include <iostream>
#define mod 1000000007
using namespace std;
long long int arr[4000001];
int n, m, k;

long long sum(int s, int e) {
	long long res = 1;
	while (s <= e) {
		if (s % 2 == 1) res = (res * arr[s]) % mod; //합구간의 왼쪽은 노드가 홀수번일 때 더한다
		if (e % 2 == 0) res = (res * arr[e]) % mod; //합구간의 오른쪽은 노드가 짝수번일 때 더한다
		s = (s + 1) / 2; //부모 노드로 올라간다. 지금 있는 곳은 계산이 끝났기 때문에 오른쪽으로 이동
		e = (e - 1) / 2; //왼쪽 부모 노드로 올라간다
	}
	return res;
}

void update(int node, long long change) {
	arr[node] = change;
	while (node > 0) {
		node /= 2;
		arr[node] = (arr[node * 2] * arr[node * 2 + 1]) % mod;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	int s = 1; //시작점 찾기, 여기서부터 거꾸로 배열이 채워질 것이다
	while (s < n) s *= 2; //세그먼트 트리 노드배열의 총개수=제곱했을 때 n을 넘는 가장 작은 어떤 수

	for (int i = 0; i < n; i++) cin >> arr[i + s]; //리프 노드

	for (int i = s; i > 0; i--) arr[i] = 1; //초기화를 꼭!! 1로 해준다!!!! 이거 안 하면 오답
	for (int i = s - 1; i > 0; i--) {
		arr[i] = (arr[i * 2] * arr[i * 2 + 1]) % mod;
	}

	for (int i = 0, a, b, c; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(b + s - 1, c);
		if (a == 2) cout << sum(b + s - 1, c + s - 1) % mod << "\n";

		//for (int i = 0; i < n + s; i++) cout << arr[i] << " ";
		//cout << endl;
	}
}
