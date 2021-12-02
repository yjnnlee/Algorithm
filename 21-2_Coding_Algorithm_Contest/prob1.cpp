#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include <stack>
#include <sstream>
using namespace std;
vector<int> page(100, 0);
vector<int> before;

int main() {
	before.push_back(0); //인덱스를 1부터 시작하기 위해

	string s;
	getline(cin, s); //공백 포함한 1줄 입력

	//1 2 3 4 B B 4 2 B F F string을 1 2 3 4 B B 42 B F F 벡터로
	stringstream ss(s);
	string token;
	vector<string> num;

	while (getline(ss, token, ' ')) {
		if (token != "") {
			num.push_back(token);
		}
	}

	bool isJump = false, isBack = false;
	int now = 0;
	for(auto x: num){
		if (x == "B") {
			if (!before.empty()) {
				//cout << "B: " << now - 1 << " Add: " << before[now - 1] << endl;
				page[before[--now]]++;
				isBack = true;
			}
		}
		else if (x == "F") {
			if (!before.empty() && now < before.size() - 1) {
				//for (auto go : before) {
				//	cout << go << " ";
				//}cout << endl;
				//cout << "before size: " << before.size() << endl;
				before.erase(before.begin() + now + 1, before.begin() + before.size() - 1); //now~점프한 숫자 사이 원소들 삭제

				//cout << "F " << now + 1 << " Add: " << before[now + 1] << endl;
				page[before[++now]]++;
				isJump = true;
			}
		}
		else {
			int index;
			stringstream ssInt(x); //string to int
			ssInt >> index;
			//cout << "index: " << index << endl;
			page[index]++;
			before.push_back(index);
		}

		if (isBack) {
			isBack = false;
		}
		else if (isJump) {
			isJump = false;
		}
		else now++;

		//cout << "now: " << now << endl;
	}

	//1~99페이지까지 방문 횟수를 출력합니다
	int tmp = 0, answer = 0;
	for (auto x : page) {
		//cout << tmp <<": " << x << endl;
		//tmp++;
		if (x > answer) answer = x;
	}

	cout << answer;
}
/*
1 2 3 4 B B 42 B F F
*/
