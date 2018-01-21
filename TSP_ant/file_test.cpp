#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

//파일 열고 데이터 넣어서 돌리고 결과 다시 파일로 출력
char *filename[10] = { "4.in", "5.in","6.in","7.in", "10.in", "12.in", "15.in","16.in","17.in","26.in"};
char *s;
int n, dist[3000][3000];

int main() {
	for (int i = 0; i < 10; i++) {
		FILE *fp;
		int n = 0;

		fp = fopen(filename[i], "r");

		if (fp == NULL) printf("파일이 없어");

		fscanf(fp, "%d", &n);
		printf("%d\n", n);

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				fscanf(fp, "%d", &dist[a][b]);
			}
		}

		//for (int a = 0; a < n; a++) {
		//	for (int b = 0; b < n; b++) {
		//		printf("%d ", dist[a][b]);
		//	}
		//	printf("\n");
		//}

		fclose(fp);
	}
}
