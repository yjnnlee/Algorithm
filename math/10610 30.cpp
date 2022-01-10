#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


/*
"길거리에서 찾은 수에 포함된 숫자들을 섞어,
30의 배수가 되는 가장 큰 수를 만든다"

처음에 문제를 봤을 때는 주어진 N값을 소인수분해해서 나온 여러 숫자들을
어케 잘 연산해서 30의 배수를 만드는 줄 알았다.
그런데 무한히 더해버리면 무한히 큰 30의 배수를 만들 수 있기 때문에 이건 아니었다

예제를 다시 보니까 "포함된 숫자"라는 의미가
주어진 N의 각각 자리수를 의미하는 것이었다
그리고 각 자리수를 어케 잘 재배치해서 가장 큰 30의 배수를 만들면 된다

30의 배수가 될 조건을 만족하는지 확인하고
각 자리수를 큰 수부터 재배치한다

30의 배수가 될 조건
1. 끝자리가 0
2. 모든 자리의 수를 더하면 3의 배수
*/

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;

	vector<int> v;
	long long sum = 0;
	for (int i = 0;i < s.size();i++) {
		int now = s[i] - '0';
		v.push_back(now);
		sum += now;
	}
	sort(v.begin(), v.end());
	if (v[0] != 0 || sum % 3 != 0) cout << -1;
	else {
		for (int i = v.size() - 1;i >= 0;i--) cout << v[i];
	}
	
}
