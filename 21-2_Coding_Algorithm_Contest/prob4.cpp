#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

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

	for (int i = 0;i < students;i++) {

			//[i]번 학생이 현재 수업을 안 듣는 경우
			//학생n의 현재 수업~마지막 수업[j]까지 비용을 제외한 나머지를 총 비용을 계산한다
			long long tmp_no_cost = 0, tmp_now_no_cost = 0;
			int tmp_no_time = limit, tmp_now_no_time = 0;
			for (int p = 0;p < students; p++) {

				if (i == p) continue; //[i]학생의 모든 수업 제외

				int longest = -1; //빠지는 학생 제외하고 가장 긴 시간 찾기
				int tmptotal = 0;
				for (int k = 0;k < students;k++) {
					if (i == k) continue;
					for (int l = i;l < classes;l++) {
						longest = max(longest, timetable[k][l]);
						tmptotal += tuition[k][l];
					}
				}

				//cout << "no_longest: " << longest << " no_tmptotal: " << tmptotal << endl;
				if (tmp_no_time - longest >= 0) { //수업 수강이 가능하면
					tmp_no_time -= longest; //시간 빼고
					tmp_no_cost = tmptotal; //비용 더하기
				}

				if (p == i) tmp_now_no_time = tmp_no_time; //현재 시간은 따로 저장해 둔다
				tmp_now_no_cost = tmptotal;
			}
			
			//[i]번 학생이 현재 수업을 듣는 경우
			//현재 수업 전체 학생들의 비용 합을 계산한다
			long long tmp_yes_cost = 0, tmp_now_yes_cost = 0;
			int tmp_yes_time = limit, tmp_now_yes_time = 0;
			for (int p = 0;p < students; p++) {

					int longest = -1; //수업 듣는 모두 중 가장 긴 시간으로 계산한다
					int tmptotal = 0;
					for (int k = 0;k < students;k++) {
						longest = max(longest, timetable[k][i]);
						tmptotal += tuition[k][i];
					}

					cout << "yes_longest: " << longest << " yes_tmptotal: " << tmptotal << endl;
					if (tmp_yes_time - longest >= 0) { //수업 수강이 가능하면
						tmp_yes_time -= longest; //시간 빼고
						tmp_yes_cost = tmptotal; //비용 더하기
					}

					if (p == i) tmp_now_yes_time = tmp_yes_time; //현재 시간은 따로 저장해 둔다
					tmp_now_yes_cost = tmptotal;
			}

			//cout << tmp_no_cost << " " << tmp_no_time << endl;
			//cout << tmp_yes_cost << " " << tmp_yes_time << endl;

			//현재([i]번) 학생이 수업을 듣지 않는 게 이득이라면 뺀다 
			if (tmp_now_no_cost > tmp_now_yes_cost) {
				for (int k = 0;k <= classes;k++) {
					ok[i][k] = 0;
				}
				answer += tmp_now_no_cost;
				limit -= tmp_now_no_time;
			}
			else {
				//아니면 놔 두고 전체 비용을 더한다
				answer += tmp_now_yes_cost;
				limit -= tmp_now_yes_time;
			}
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
