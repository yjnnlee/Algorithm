#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int s,k,h;
	cin >> s >> k >> h;
	int minn = min(s, min(k, h));
	if (s + k + h >= 100) cout << "OK";
	else if (minn == s) cout << "Soongsil";
	else if (minn == h) cout << "Hanyang";
	else cout << "Korea";
}
