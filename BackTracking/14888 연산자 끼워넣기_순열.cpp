#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
long long maxx = -1e9, minn = 1e9;
void cal(vector<int>& v, vector<int>& d) {
	long long sum = v[0];
	for (int i = 0; i < n-1;i++) {
		if (d[i] == 0) sum += v[i+1];
		if (d[i] == 1) sum -= v[i+1];
		if (d[i] == 2) sum *= v[i+1];
		if (d[i] == 3) sum /= v[i+1];
	}
	
	if (sum > maxx) maxx = sum;
	if (sum < minn) minn = sum;
}
int main() {
	cin >> n;
	vector<int> v(n+1), d;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	for (int i = 0;i < 4;i++) {
		int tmp; cin >> tmp;
		for (int j = 0;j < tmp;j++) d.push_back(i);
	}

	cal(v, d);
	while (next_permutation(d.begin(), d.end())) {
		cal(v, d);
	}

	cout << maxx << "\n" << minn;
}
