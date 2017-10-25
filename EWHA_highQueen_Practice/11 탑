#include <stdio.h>
#include <utility>
#include <stack>
using namespace std;
int n, a, max=0;
stack<pair<int, int>> s; //값, 인덱스

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		
		while(!s.empty()){
			if (s.top().first > a){ //지금 값이 스택의 탑보다 큼=수신가능
				printf("%d ", s.top().second);
				break;
			}
			s.pop();
		}

		if (s.empty()) printf("0 ");
		s.push(make_pair(a, i));
	}
}
