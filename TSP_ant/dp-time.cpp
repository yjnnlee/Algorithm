#include <cstdio> 
#include <cmath>
#include <Windows.h>
#include <algorithm> 
#include <time.h>

#define MAX_VALUE 987654321
using namespace std;
int n; //경로를 저장할 dp 
int cache[3000][65536], dist[3000][3000];

time_t startTime = 0, endTime = 0;

char *filename[10] = { "4.in", "5.in","6.in","7.in", "10.in", "12.in", "15.in","16.in","17.in","26.in" };
char *out_filename[10] = { "4.out", "5.out","6.out","7.out", "10.out", "12.out", "15.out","16.out","17.out","26.out" };
char *s;

int TSP(int cur, int visited) {
	//점이 10개라면, 100000000000-1 =011111111111; 
	if (visited == (1 << n) - 1) return dist[cur][0];

	int& ret = cache[cur][visited];
	if (ret != 0) return ret;
	ret = MAX_VALUE;
	for (int next = 0; next <= n; next++) {
		if (visited&(1 << next))continue;
		if (dist[cur][next] == 0) continue;
		ret = min(ret, TSP(next, visited | (1 << next)) + dist[cur][next]);
	}
	return ret;
}

int main() {
	for (int i = 0; i < 10; i++) {
		FILE *fp;
		FILE *ffp;
		int n = 0;
		for (int a = 0; a < 3000; a++) {
			for (int b = 0; b < 65536; b++) {
				dist[a][b] = 0;
				cache[a][b] = 0;
			}
		}

		fp = fopen(filename[i], "r");
		ffp = fopen(out_filename[i], "w");

		fscanf(fp, "%d", &n);
		printf("%d\n", n);

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				fscanf(fp, "%d", &dist[a][b]);
			}
		}

		startTime = clock();
		printf("%d\n", TSP(0, 1));
		
		endTime = clock();
		float duringtime = (float)(endTime - startTime) / (CLOCKS_PER_SEC);

		printf("\n%f", duringtime);

		printf("i: %d\n", duringtime);
		fprintf(ffp, "%f", duringtime);
		fclose(fp);
		fclose(ffp);
	}
}