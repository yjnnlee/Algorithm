#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main() {
	FILE *fp1, *fp2;
	fp1 = fopen("09.in", "w");

	srand(time(NULL));

	//int tmp = rand() % 1000 + 1;
	int tmp = 860;

	fprintf(fp1, "%d \n", tmp);

	for (int i = 0; i < tmp; i++) {
	again2:
		int tmp3 = rand() % 10000 + 1;
	again:
		int tmp4 = rand() % 9999 + 1;

		if (tmp3 <= tmp4) { //tmp4가 크거나 같으면 안됨
			goto again;
		}

		if ((tmp3 - 1) % (tmp4 + 1) == 0) { //배수면 안됨
			goto again2;
		}

		fprintf(fp1, "%d %d\n", tmp3, tmp4);
	}

	fclose(fp1);
	return 0;
}
