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
1.재귀 https://github.com/proqk/Algorithm/blob/master/BruteForce/14889%20%EC%8A%A4%ED%83%80%ED%8A%B8%EC%99%80%20%EB%A7%81%ED%81%AC.cpp
2.순열
3.비트마스크
*/

int map[25][25];
int n;
int res = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	//순열에 쓸 0,1 벡터
	vector<int> v;
	for (int i = 0; i < n / 2; i++) v.push_back(0);
	for (int i = 0; i < n / 2; i++) v.push_back(1);

	do {
		vector<int> start, link;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) start.push_back(i + 1); //v가 0이면 start팀
			else link.push_back(i + 1); //1이면 link팀
		}

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
	} while (next_permutation(v.begin(), v.end())); //모든 순열에 대해서
	
	cout << res;
}
