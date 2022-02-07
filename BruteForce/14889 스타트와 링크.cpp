#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

/*
처음 접근: 미리 합을 다 구해두고 그 중 최소를 구하는 식으로 했는데
다 하고 다시 보니까 2명 이상도 팀이 가능하더라..

그래서

1. n명의 사람을 n/2명, n/2명 이렇게 두 팀으로 나눈다
2. 각 팀의 능력치 계산 (2명씩 추출)
3. 두 팀 총 능력치 차이의 최소값 계산, 갱신

2,3은 단순 계산이므로 1번 과정이 중요
재귀로 일단 접근했는데 20이 최대라 그런지 시간초과는 안 걸림
좀만 넘기면 바로 시간초과일 듯
순열, 비트마스크로도 풀 수 있다고 함
*/

int map[25][25];
int n;
int res = 1e9;

vector<int> start, link;

void go(int index) {
	if (index == n + 1) {
		if (start.size() == n / 2 && link.size() == n / 2) {

			int sum_start = 0, sum_link = 0;

			for (int i = 0; i < n / 2; i++) {
				for (int j = i + 1; j < n / 2; j++) {
					if (i == j) continue;

					//스타트팀 2명 선택
					sum_start += map[start[i]][start[j]] +
						map[start[j]][start[i]];

					//링크팀 2명 선택
					sum_link += map[link[i]][link[j]] +
						map[link[j]][link[i]];
				}
			}

			res = std::min(res, abs(sum_start - sum_link));
		}
		return;
	}

	//index 선수에 대해서
	//1. start팀에 넣는다
	start.push_back(index);
	go(index + 1);
	start.pop_back();

	//2. linkk팀에 넣는다
	link.push_back(index);
	go(index + 1);
	link.pop_back();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	
	go(1);
	cout << res;
}
