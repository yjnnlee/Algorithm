#include <iostream>
#include <vector>
using namespace std;

int a, n, i = 0;
vector<int> res(n);

int main() {
	cin >> a;

	for (int j = 0; j < a; j++) {
		cin >> n;

		while (n > 0) {
			if (n % 2 == 1) {
				res.push_back(i);
			}
			n /= 2;
			i++;
		}

		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		res.clear();
		i = 0;
	}
}
