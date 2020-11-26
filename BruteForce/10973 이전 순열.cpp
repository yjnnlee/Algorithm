#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool prev_permutation(vector<int> &a, int n){
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) i -= 1; //(1번)
	if (i <= 0) return false; //만약 마지막 순열이라면 끝난다
	int j = n - 1;
	while (a[j] >= a[i - 1]) j -= 1; //(2번)
	swap(a[i - 1], a[j]); //(3번)
	j = n - 1;
	while (i < j) { //(4번)
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (prev_permutation(a, n)) {
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
	}
	else cout << -1;
}
