#include <stdio.h>
int visited = 0;
unsigned int next = 1;

int main() {
	printf("%d\n", visited & (1 << (next - 1)) != 0); //0

	printf("%d\n", visited + (1 << (next - 1))); //1

	printf("%d", visited + (1 >> (next))); //0
}