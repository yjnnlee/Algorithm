#include <iostream>
#include <string>
using namespace std;
int n, cnt=0;
int main() {
	scanf("%d", &n);
	for (int i = 666;; i++) {
		string s = to_string(i);
		if (s.find("666") != -1) { //뭐라도 666이 걸리면
			cnt++;
		}
		if (cnt == n) {
			printf("%d", i);
			return 0;
		}
	}
}
