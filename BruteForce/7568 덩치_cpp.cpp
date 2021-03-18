#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first > b.first;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v; // v(51)로 범위를 잡아버리면 제대로 출력 안 됨 왜지?
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	int go = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { //더 큰 게 있으면 등수 다운
			if (v[i].first < v[j].first && v[i].second < v[j].second) go++;
		}
		cout << go << " ";
		go = 1;
	}
}

//5
//88 186
//60 175
//55 185
//58 183
//46 155
