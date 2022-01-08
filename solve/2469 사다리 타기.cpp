#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int k, n;
string res, s, out;
string map[1005];
int findline;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> k >> n >> res;
	for(int i=0;i<k;i++) s.push_back('A' + i);

	for (int i = 0;i < n;i++) {
		cin >> map[i];
		if (map[i][0] == '?') findline = i; //?인 행의 인덱스
	}

	/*
	시작 문자열: s
	결과 문자열: res

	시작은 시작부터 ????행까지 사다리를 타고 내려오고,
	결과는 마지막부터 ????행까지 사다리를 타고 올라온다.
	????행에서 시작과 결과를 비교하고 같으면 *이고 아니면 -로 바꾼다

	사다리에서 -를 만나면 i와 i+1를 스왑한다
	*/
	for (int i = 0;i < findline;i++) { // 시작~?전까지 
		for (int j = 0;j < map[i].size();j++) {
			if (map[i][j] == '-') { // -가 있으면 자리를 바꾼다
				swap(s[j], s[j + 1]); //시작 문자열 스왑
			}
		}
	}
	for (int i = n-1;i > findline;i--) { // ?부터 끝까지 
		for (int j = 0;j < map[i].size();j++) {
			if (map[i][j] == '-') { // -가 있으면 자리를 바꾼다
				swap(res[j], res[j + 1]); //마지막 문자열 스왑
			}
		}
	}

	bool flag = true;
	for (int i = 0;i < k-1;i++) {
		if (s[i] == res[i]) out.push_back('*');
		else if (s[i] == res[i + 1]) {
			out.push_back('-');
			swap(s[i], s[i + 1]);
		}
		else { //불가능한 경우
			flag = false;
			break;
		}
	}

	if (flag) cout << out;
	else for (int i = 0;i < k-1;i++) cout << "x";
}
