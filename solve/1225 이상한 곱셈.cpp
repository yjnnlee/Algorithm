#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string n, m;
	cin >> n >> m;
	long long sum = 0;
	for (int i = 0; i < n.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			sum += (n[i] - '0') * (m[j] - '0');
		}
	}
	cout << sum;
}
