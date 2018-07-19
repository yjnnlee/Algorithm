#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

stack<int> a;
int n, res;
char arr[100];

int main() {

//	for(int i=0;i != scanf("%[^\n]s"); i++){
	while (1) {
		scanf("%s", &arr);
		for (int i = 0; i < strlen(arr); i++) {
			if (arr[i] == '+' || arr[i] == '-' || arr[i] == '/' || arr[i] == '*') {
				int second = a.top();
				int first = a.top();
				if (arr[i] == '+') res = first + second;
				else if (arr[i] == '-') res = first - second;
				else if (arr[i] == '*') res = first * second;
				else res = first / second;

				a.pop();
				a.pop();
			}
			else a.push(arr[i]);
		}
		if (a.empty()) break;
	}
	printf("%d", res);
}