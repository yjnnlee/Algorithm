#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int n;
		cin >> n;
		if (n == -1) return 0;
		vector<int> v;

		long long sum = 0;
		for (int i = 1; i < n; i++) { //약수 구하기
			if (n % i == 0) {
				sum += i;
				v.push_back(i);
			}
		}

		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < v.size(); i++) {
				if (i == v.size() - 1) cout << v[i];
				else cout << v[i] << " + ";
			}
		}
		else {
			cout << n << " is NOT perfect.";
		}
		cout << "\n";
	}
}
