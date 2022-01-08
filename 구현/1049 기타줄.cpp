#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;
int set = 1001, one = 1001;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		set = min(set, a);
		one = min(one, b);
	}

	int ans = 0;
	if (set < one * 6) ans += set * (n / 6); //6개 세트가 이득
	else ans += one * (n / 6) * 6; //낱개가 이득
	n %= 6;

	//6배수 빼고 나머지 잉여를 세트 하나로 퉁 칠 것인지 아니면 낱개 살 것인지
	if (set > one * n) ans += one * n; //낱개
	else ans += set; //세트 하나

	cout << ans;
}
