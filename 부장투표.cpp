#include <stdio.h>
#include<stdlib.h>
#include <Windows.h>

char name[100][100];
int i = 1;
int vote = 1, data[100];

int main() {
	while (true) {
		printf("%d: ", i);
		scanf("%s", &name[i]);
		if (name[i][0] == '0') {
			break;
		}
		++i;
	}
	system("cls");

	while (vote) {
		for (int j = 1; j < i; j++) {
			printf("%d: %s\n", j, name[j]);
		}
		printf("\n\n투표: ");
		scanf("%d", &vote);
		
		if (vote > i -1) {
			printf("\nㄴㄴㄴㄴ");
			Sleep(1000);
		}
		else {
			++data[vote];
		}

		system("cls");
	}

	printf("\n\n\n");
	for (int j = 1; j < i; j++) {
		printf("\n%d: %s ------ %d표\n", j, name[j], data[j]);
	}
	printf("\n\n\n");
}
