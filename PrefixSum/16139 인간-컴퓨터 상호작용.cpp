#include <iostream>
#include <string.h>
using namespace std;
int n, m, map[200005][30];
char s[200005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); //시간초과 방지
	cin >> s >> n;
	int len = strlen(s);
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j < 26; j++) map[i][j] = map[i - 1][j];
		++map[i][s[i - 1] - 'a'];
	}

	//for (int i = 1; i <= len; i++) {
	//	for (int j = 0; j < 26; j++)
	//		cout << map[i][j] << ' ';
	//	cout << endl;
	//}

	for (int i = 1; i <= n; i++) {
		int a, b;
		char alpa;
		cin >> alpa >> a >> b;
		cout << map[b + 1][alpa - 'a'] - map[a][alpa - 'a'] << '\n';
		//b+1인 이유: 문자열을 0번부터 세기 때문에 근데 위에서 1부터 했으니까
	}
}
