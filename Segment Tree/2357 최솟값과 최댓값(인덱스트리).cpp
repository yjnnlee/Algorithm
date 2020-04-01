#include <iostream>
using namespace std;
long long int arr[4000001], arr2[4000001];
int n, m, minnum = 1000000001, maxnum = 0;

void findnum(int s, int e) {
	while (s <= e) {
		if (s % 2 == 1) { //합구간의 왼쪽은 노드가 홀수번일 때
			if (minnum > arr[s]) minnum = arr[s];
			if (maxnum < arr2[s]) maxnum = arr2[s];
		}
		if (e % 2 == 0) { //합구간의 오른쪽은 노드가 짝수번일 때
			if (minnum > arr[e]) minnum = arr[e];
			if (maxnum < arr2[e]) maxnum = arr2[e];
		}
		s = (s + 1) / 2; //부모 노드로 올라간다. 지금 있는 곳은 계산이 끝났기 때문에 오른쪽으로 이동
		e = (e - 1) / 2; //왼쪽 부모 노드로 올라간다
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
		arr2[i + s] = arr[i + s];
	}
	for (int i = s - 1; i > 0; i--) {
		if (arr[i * 2] < arr[i * 2 + 1]) arr[i] = arr[i * 2]; //최소값 트리
		else arr[i] = arr[i * 2 + 1];

		//만약 비교값 한 쪽이 0이면(값이 없으면) 최소값은 0이 아니라 존재하는 값이다
		if (arr[i * 2] == 0 && arr[i * 2 + 1]) arr[i] = arr[i * 2 + 1];
		else if (arr[i * 2 + 1] == 0 && arr[i * 2]) arr[i] = arr[i * 2];
	}

	for (int i = s - 1; i > 0; i--) {
		if (arr2[i * 2] > arr2[i * 2 + 1]) arr2[i] = arr2[i * 2]; //최대값 트리
		else arr2[i] = arr2[i * 2 + 1];
	}
	
	//for (int i = 0; i < n + s; i++) cout << arr[i] << " ";
	//cout << endl;
	//for (int i = 0; i < n + s; i++) cout << arr2[i] << " ";
	//cout << endl;

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		findnum(a + s - 1, b + s - 1);
		cout << minnum << " " << maxnum << "\n";
		minnum = 1000000001; maxnum = 0;
	}
}
