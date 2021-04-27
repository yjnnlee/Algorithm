#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int t;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	int a[3] = { 0,0,0 };
	int b[] = { 300,60,10 };
	int sum = 0, i = 0;
	if (t % 10) {
		cout << -1;
		return 0;
	}

	while (sum < t) {
		if (sum == t) break;
		if (sum > t) {
			cout << -1;
			return 0;
		}
		if (sum + b[i] <= t) {
			while (sum + b[i] <= t) {
				sum += b[i];
				a[i]++;
			}
		}
		i++;
	}
	for (auto x: a) {
		cout << x << " ";
	}
}
