#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
int main(void) {
	char solutions[10][100] = {
		"meet at midnight",
		"thanks god it is friday",
		"close the door",
		"enemy at the gate",
		"superman returns",
		"return of jedi",
		"phantom of the opera",
		"sex and the city",
		"lord of the rings",
		"fourth of july"
	};
	srand(time(NULL));
	int solution_num = rand() % 10; //랜덤으로 문장 하나를 고름
	char answer[100];
	char ch;
	int i, j = 0;

	//랜덤으로 고른 문장에 맞춰서 밑줄을 만듦
	int len = strlen(solutions[solution_num]);
	for (int k = 0; k < len; k++) {
		if (solutions[solution_num][k] == ' ') answer[k] = ' ';
		else answer[k] = '_';
	}

	while (1) {
		printf("\n문자열을 입력하시오: ");
		for (int k = 0; k<len; k++) printf("%c", answer[k]);
		printf("\n글자를 추측하시오(시도횟수%d): ", j);
		ch = getch();
		for (i = 0; solutions[solution_num][i] != NULL; i++) {
			if (solutions[solution_num][i] == ch)
				answer[i] = ch;
		}
		if (strncmp(solutions[solution_num], answer, len) == 0) {
			printf("\n");
			for (int k = 0; k<len; k++) printf("%c", answer[k]);
			printf("\n정답!!\n");
			break;
		}
		if (j == 10) {
			printf("\n너무 많이 틀렸습니다ㅠ");
			return 0;
		}
		j++;
	}
	return 0;
}
