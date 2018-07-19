#include <stdio.h>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

int n, w[3000][3000], res = 1e9, tmp;
LARGE_INTEGER Frequency;
LARGE_INTEGER BeginTime;
LARGE_INTEGER Endtime;

char *filename[10] = { "4.in", "5.in","6.in","7.in", "10.in", "12.in", "15.in","16.in","17.in","26.in" };
char *out_filename[10] = { "4.out", "5.out","6.out","7.out", "10.out", "12.out", "15.out","16.out","17.out","26.out" };
char *s;

int tsp(vector<int> &go, vector<bool> &visited, int nowLen) {
	if (go.size() == n) {
		return nowLen + w[go.back()][go[0]]; //다 방문했으면 처음으로
	}


	for (int i = 0; i < n; i++) {
		if (visited[i] == 1 || w[i] == 0) continue;

		int cur = go.back();
		go.push_back(i);
		visited[i] = true;

		tmp = tsp(go, visited, nowLen + w[cur][i]);
		res = min(res, tmp);
		visited[i] = false;
		go.pop_back();

	}
	return res;
}

int main() {
	for (int i = 0; i < 10; i++) {
		FILE *fp;
		FILE *ffp;
		int n = 0;

		fp = fopen(filename[i], "r");
		ffp = fopen(out_filename[i], "w");

		fscanf(fp, "%d", &n);
		printf("%d\n", n);

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				fscanf(fp, "%d", &w[a][b]);
			}
		}

		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&BeginTime);

		vector<bool> visited(n); //방문했는지
		vector<int> go(1, 0); //여행하는 경로

		visited[0] = true;
		printf("%d\n", tsp(go, visited, 0));

		QueryPerformanceCounter(&Endtime);
		int elapsed = Endtime.QuadPart - BeginTime.QuadPart;
		double duringtime = (double)elapsed / (double)Frequency.QuadPart;

		printf("i: %d\n", duringtime);
		fprintf(ffp, "%f", duringtime);
		fclose(fp);
		fclose(ffp);
	}
}
