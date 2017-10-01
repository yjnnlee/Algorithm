#include <iostream>
#include <string>
#include <vector>
using namespace std;

string n;
vector<int> phone;

int main() {
	cin >> n;

	for (int i = 0; i < n.size(); i++) {
		if (n[i] >= '0' && n[i] <= '9') {
			cout << n[i];
		}
	}
}
