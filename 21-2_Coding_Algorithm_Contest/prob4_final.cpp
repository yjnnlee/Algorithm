#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
struct b {
	int p, d;
};
vector<b> a;

/*
[학생n의 현재 수업을 안 듣는 경우]
학생n의 현재 수업~마지막 수업까지의 총 비용을 제외해야 한다

즉, 현재 수업 나머지 학생들의 수업~마지막까지의 총 비용
근데 if 시간<총시간일 때만 합한다
시간은 빠지는 학생 제외한 애들 중 가장 긴 시간으로 계산한다
vs
[학생n이 현재 수업을 듣는 경우]
현재 수업 전체 학생들의 비용 합
시간은 수업 듣는 모두 중 가장 긴 시간으로 계산한다
*/

int limit;
int students, classes; //학생의 수, 수업의 수
long long answer = 0;
int dp[1000][1000];

int main() {
	cin >> students >> classes;

	//학생수*수업수 2차원 벡터 0으로 초기화
	vector<vector<int>> timetable(students+1, vector<int>(classes+1, 0));
	vector<vector<int>> tuition(students+1, vector<int>(classes+1, 0));
	vector<vector<int>> ok(students+1, vector<int>(classes+1, 1)); //수업을 듣는지 여부. 들으면 비용을 넣는다.

	for (int i = 0;i < students;i++) {
		for (int j = 0;j < classes;j++) {
			cin >> timetable[i][j];
		}
	}
	for (int i = 0;i < students;i++) {
		for (int j = 0;j < classes;j++) {
			cin >> tuition[i][j];
		}
	}
	cin >> limit;

	int maxcost = 0;
	for (int i = 0;i < students;i++) {
		for (int j = 0;j < classes;j++) {
			a.push_back({ timetable[i][j], tuition[i][j] });
			if (maxcost < tuition[i][j]) maxcost = tuition[i][j];
		}
	}

	sort(a.begin(), a.end(), [](b u, b d) {
		if (u.d != d.d) return u.d > d.d; //d값 내림차순 정렬
		else return u.p < d.p;
	});
	
	int len = students * classes;

	int now_time = 0;
	for (int i = 0;;i++) {		
		now_time += a[i].p;
		//cout << answer << endl;		
		if (limit - now_time < 0) break;
		answer += a[i].d;

	}
	cout << answer;
}
/*
input
3
3
3 7 5
1 8 1
1 1 1
1 2 10
1 1 1 
2 2 2
15
output
20

input
3
4
0 0 0 2
0 0 0 1
0 1 0 0
1 1 1 1
1 1 1 1
0 0 0 100
2

output
107

time-00:10:02
*/
