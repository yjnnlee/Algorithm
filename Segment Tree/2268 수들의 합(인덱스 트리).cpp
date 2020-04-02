#include <iostream>
using namespace std;
long long int arr[4000001];
int n, m, k;

long long sum(int s, int e) {
	long long res = 0;
	while (s <= e) {
		if (s % 2 == 1) res += arr[s]; //합구간의 왼쪽은 노드가 홀수번일 때 더한다
		if (e % 2 == 0) res += arr[e]; //합구간의 오른쪽은 노드가 짝수번일 때 더한다
		s = (s + 1) / 2; //부모 노드로 올라간다. 지금 있는 곳은 계산이 끝났기 때문에 오른쪽으로 이동
		e = (e - 1) / 2; //왼쪽 부모 노드로 올라간다
	}
	return res;
}

void update(int node, long long int val) { //ex.3이 6으로 바뀐다->3이 관련된 곳마다 6-3=3씩 더해진다
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
	//n=12일 때 어떤 수는 4, 4^2=16이기 때문

	//for (int i = 0; i < n; i++) cin >> arr[i + s]; //리프 노드

	for (int i = s - 1; i > 0; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1]; //뒤에서부터 나머지 합 배열을 채운다

	for (int i = 0, a, b, c; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(b + s - 1, c - arr[b + s - 1]);
		if (a == 0) {
			if(b<c) cout << sum(b + s - 1, c + s - 1) << "\n";
			else cout << sum(c + s - 1, b + s - 1) << "\n";
		}
	}
}
