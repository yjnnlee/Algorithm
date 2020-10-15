#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> v;
int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	if (n == 0) { cout << 0; return 0; }
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	double per = n * 0.15f; //퍼센트
	int peo = floor(per + 0.5); //반올림
	sort(v.begin(), v.end());
	for (int i = 0; i < peo; i++) v.pop_back();
	int sum = 0;
	for (int i = peo; i < v.size(); i++) sum += v[i];
	cout << floor(((double)sum / (double)(n - peo * 2)) + 0.5);
}
