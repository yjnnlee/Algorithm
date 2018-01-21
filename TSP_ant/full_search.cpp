#include <stdio.h>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

int n, w[3000][3000], res = 1e9, tmp;
//LARGE_INTEGER Frequency;
//LARGE_INTEGER BeginTime;
//LARGE_INTEGER Endtime;

int tsp(vector<int> &go, vector<bool> &visited, int nowLen) {
	if (go.size() == n) { return nowLen + w[go.back()][go[0]]; } //다 방문했으면 처음으로

	for (int i = 0; i < n; i++) {
		if (visited[i] == 1 || w[i] == 0) continue;

		int cur = go.back();
		go.push_back(i);
		visited[i] = true;

		tmp = tsp(go, visited, nowLen+w[cur][i]);
		res = min(res, tmp);
		visited[i] = false;
		go.pop_back();
		
	}
	return res;
}

int main() {
	//QueryPerformanceFrequency(&Frequency);
	//FILE *f;
	//f = fopen("testEvery.out", "w");

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}

	//QueryPerformanceCounter(&BeginTime);

	vector<bool> visited(n); //방문했는지
	vector<int> go(1,0); //여행하는 경로

	visited[0] = true;
	printf("%d", tsp(go, visited, 0));

	//QueryPerformanceCounter(&Endtime);
	//int elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	//double duringtime = (double)elapsed / (double)Frequency.QuadPart;

	//printf("\n%f\n\n", duringtime);
	//fprintf(f, "%f", duringtime);
	//fclose(f);
}
//0.374826
