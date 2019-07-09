#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
int n, num[30];
char a[101];
stack<double> s;

int main() {
	scanf("%d%s", &n, a);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			s.push(num[a[i] - 'A']);
		}
		else {
			if (a[i] == '+') {
				double a = s.top();
				s.pop();
				double b = s.top();
				s.pop();
				s.push((double)b + (double)a);
			}
			else if (a[i] == '-') {
				double a = s.top();
				s.pop();
				double b = s.top();
				s.pop();
				s.push((double)b - (double)a);
			}
			else if (a[i] == '*') {
				double a = s.top();
				s.pop();
				double b = s.top();
				s.pop();
				s.push((double)b * (double)a);
			}
			else {
				double a = s.top();
				s.pop();
				double b = s.top();
				s.pop();
				s.push((double)b / (double)a);
			}
		}
	}
	printf("%.2lf", s.top());
}
