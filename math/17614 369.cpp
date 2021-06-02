#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
using namespace std;
int main() {
	long long n;
	cin >> n;
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '3' || s[j] == '6' || s[j] == '9') {
				res++;
			}
		}
	}
	cout << res;
}
