#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> egg;

/*
*      내구도    무게
계란1:   7        5
계란2:   3        4

계란1->계란2 치기

*      내구도    무게
계란1:   3        5
계란2:  -2        4
->무게만큼 공격하고, 상대방 무게만큼 내구도가 깎인다

계란은 왼쪽부터 시작해서 오른쪽에 있는 계란 중 1개를 깬다
->a로 b를 공격했는데 안 깨진다 해도 일단 공격해야 한다
->손에 있는 계란이 이미 깨졌거나, 깰 계란이 남아있지 않으면 패스
다음 계란을 집는다
가장 오른쪽 계란을 집으면 종료

a의 무게 > b의 내구도 -> b깨짐, a내구도-b무게, b내구도-a무게

무조건 한 번에 깰 수 있는 경우가 좋다
*/

int go(int now) {
	if (now == n) {
		int cnt = 0;
		for (int i = 0;i < n;i++) {
			if (egg[i].first <= 0) cnt += 1; //깨진 애들 세기
		}
		return cnt;
	}

	//int now_a = egg[now].first; //현재 내구도
	//int now_b = egg[now].second; //현재 무게

	if (egg[now].first <= 0) return go(now + 1);

	int res = 0; //res여기다 놔도 됨
	//어차피 재귀 돌면서 tmp가 쌓이고, 그 아래 if에서
	//한 번에 res계산 한 뒤에 바로 내려가서 return하니까

	bool is_possible = false;
	//=now계란으로 다른 계란을 칠 수 있는가?
	//계란 칠 수 있는 게 없으면 그냥 패스,
	//칠 수 있는 게 있다면 내구도 빼고 패스해야 하기 때문
	//now빼고 다 깨진 계란인 경우 등..

	for (int i = 0;i < n;i++) {
		//오르쪽 탐색이라고 굳이 now+1~n으로 할 필요 없음
		//어차피 다 따지면 되므로 0~n하고 자기 자신만 패스
		if (now == i) continue;

		//int you_a = egg[i].first; //내구도
		//int you_b = egg[i].second; //무게
		if (egg[i].first > 0) { //이미 깨진 계란은 못 침
			is_possible = true;
			egg[now].first -= egg[i].second;
			egg[i].first -= egg[now].second;
			int tmp = go(now + 1); //다음 진행
			//cout << tmp << endl;
			if (res < tmp) res = tmp; //최소값
			egg[now].first += egg[i].second;
			egg[i].first += egg[now].second; //돌려두기
		}

		// 아래 코드는 깨질 때 깬다는 코드인데, 한 번만 탐색하는 게 아닌
		// 백트레킹으로 다 탐색해야 하니까 이건 적절하지 않음
		// 그냥 다 깨버리고 최소값만 찾으면 된다
		//if (now_b >= you_a) {
		//	egg[now].first -= you_b;
		//	egg[i].first -= now_b;
		//	break;
		//}
	}
	if (!is_possible) return go(now + 1);
	//return으로 해야 함. 그래야 cnt 반환할 때 res말고 cnt반환
	return res; 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie();
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a, b; cin >> a >> b;
		egg.push_back({ a,b }); //내구도, 무게
	}
	
	/*for (int i = 0;i < n;i++) {
		cout << egg[i].first << " " << egg[i].second << endl;
	}*/

	cout << go(0);
	return 0;
}
