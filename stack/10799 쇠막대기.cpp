#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;

int idx = 0; //쇠막대기
int total = 0;
char arr[100001];

int main() {
	stack<char> a;
	scanf("%s", arr);
	int len = strlen(arr);

	for (int i = 0; i < len; i++) {
		if (arr[i] == '(') {
			a.push(arr[i]);
		}
		else if (arr[i] == ')') {
			a.pop();
			if (arr[i - 1] == '(') {
				total += a.size();
			}
			else {
				total += 1;
			}
		}
	}
	printf("%d", total);
}
