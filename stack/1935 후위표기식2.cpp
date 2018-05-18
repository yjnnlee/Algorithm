#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;

int b_index = 0;
char b[100], a[100];

//중위표현식에서 후위표현식으로
void IntoPost(char a[]) {
	stack<char> cal;
	b_index = 0;

	for (int i = 0; i < strlen(a); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			b[b_index++] = a[i]; //숫자는 바로 후위배열에 저장
		}
		else { //숫자가 아니면 연산자

			//여는 괄호는 무조건 스택에 넣음
			if (a[i] == '(') {
				cal.push(a[i]);
			}

			else if (a[i] == ')') { //닫는 괄호 만나면 여는 괄호까지 pop
				while (cal.top() != '(') { //여는 괄호까지
					b[b_index++] = cal.top(); //후위배열에 저장하고
					cal.pop(); //팝
				}
				cal.pop(); //'('없앰
			}

			//우선순위가 a[i]보다 높거나 같은 것들을 pop
			//곱셈과 나눗셈보다 우선순위가 높은 것은 없음
			else if (a[i] == '*' || a[i] == '/') {
				while (!cal.empty() && (cal.top() == '*' || cal.top() == '/')) {
					b[b_index++] = cal.top();
					cal.pop();
				}
				cal.push(a[i]);
			}

			else { //더하기 빼기인 경우
				while (!cal.empty() && cal.top() != '(') {
					//우선순위가 a[i]보다 높거나 같은 것들 pop할껀데
					//더하기 빼기가 제일 우선순위가 낮으므로 '('나 스택이 빌 때까지 pop
					b[b_index++] = cal.top();
					cal.pop();
				}
				cal.push(a[i]);
			}
		}
	}
	//스택에 남은 것들 전부 pop
	while (!cal.empty()) {
		b[b_index++] = cal.top();
		cal.pop();
	}

	for (int i = 0; i < b_index; i++) {
		printf("%c", b[i]);
	}
}

//후위표현식 문자열 내용을 읽어 계산하고 결과 출력
int PostCalculator(char b[]) {
	stack<char> s;
	int l, r;

	for (int i = 0; i < strlen(b); i++) {
		if (b[i] >= 'A' && b[i] <= 'Z') {
			s.push(b[i] - '0'); //정수로 만들어서 스택에 저장
		}
		else { //연산자라면
			r = s.top();
			s.pop();
			l = s.top();
			s.pop();

			switch (b[i]) {
			case '+':
				s.push(r + l); break;
			case '-':
				s.push(l - r); break;
			case '*':
				s.push(r * l); break;
			case '/':
				s.push(l / r); break;
			}
		}
	}
	return s.top();
}

int main() {
	int n;
	scanf("%d %s", &n, a);
	while (n--){
		
	}
}
