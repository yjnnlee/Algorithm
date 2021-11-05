#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;

/*
2와 5로 나누어지지 않는 정수 n중, 1로만 이루어진 n의 배수
2와 5의 배수가 아니면서 1로만 이루어진 n의 배수
1%n
11%n
111%n
1111%n ... 해 보기

1이 73개 % N = 1이면
1이 74개인 수는 ((1이 73개) * 10 + 1) % N이므로(N은 변하는 수한테만)
1이 74개인 수는 (1*10+1) = 11%N이다
*/
int main() {
	ios_base::sync_with_stdio(false); cin.tie();
	while (cin >> n) {
		int num = 0; //이전까지의 수가 계속 갱신 됨
		for (int i = 1;;i++) {
			num = num * 10 + 1;
			num %= n;
			if(num==0){
				cout << i << "\n";
				break;
			}
		}
	}
}
