#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int n, tmp;
char what[10];
queue<int> s;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s", what);
		if (strcmp(what, "push") == 0) {
			scanf("%d", &tmp);
			s.push(tmp); //삽입
		}
		else if (strcmp(what, "front") == 0) {
			if (s.empty()) printf("-1\n"); //empty-비어있으면 1 아니면 0
			else printf("%d\n", s.front()); //맨 마지막 데이터
		}
		else if (strcmp(what, "back") == 0) {
			if (s.empty()) printf("-1\n"); //empty-비어있으면 1 아니면 0
			else printf("%d\n", s.back()); //맨 마지막 데이터
		}
		else if (strcmp(what, "size") == 0) {
			printf("%d\n", s.size()); //사이즈 출력
		}
		else if (strcmp(what, "empty") == 0) {
			if (s.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(what, "pop") == 0) {
			if (s.empty()) printf("-1\n");
			else printf("%d\n", s.front()), s.pop(); //top은 출력만, 삭제는 pop
		}
	}
}
