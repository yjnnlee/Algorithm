#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) v.push_back(i+1);
	int index = 0;
	string res;
	m--;
	res += "<";
	for (int i = 0; i < n - 1; i++) {
		index += m;
		if (index >= v.size()) index %= v.size();
//		cout << v[index] << endl;
		res+= to_string(v[index])+", ";
		v.erase(v.begin() + index);
	}
	res += to_string(v.front());
	res += ">";
	cout << res;
}
