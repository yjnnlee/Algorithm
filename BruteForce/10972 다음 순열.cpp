#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool next_permutation(vector<int> &a, int n){
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1; //뒤에서 앞으로 가면서 i-1>i가 아니면 끝(1번)
	if (i <= 0) return false; //만약 마지막 순열이라면 끝난다
	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1; //뒤에서 앞으로 가면서 크면서 가장 작은 수를 구한다(2번)
	swap(a[i - 1], a[j]); //두 수의 위치를 바꾼다 (3번)
	j = n - 1;
	while (i < j) { //i<n-1까지의 수열을 뒤집는다
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true; //다음 수열이 존재한다 true
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (next_permutation(a, n)) {
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
	}
	else cout << -1;
}
