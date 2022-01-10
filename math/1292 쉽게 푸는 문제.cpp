#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	vector<int> v;
	for (int i = 1;i <= b;i++) {
		for (int j = 0;j < i;j++) {
			v.push_back(i);
		}
	}

	long long sum = 0;
	for (int i = a-1;i <= b-1;i++) {
		sum += v[i];
	}
	cout << sum;
}
