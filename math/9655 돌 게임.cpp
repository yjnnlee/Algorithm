#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	if (n % 2 == 1) cout << "SK"; //홀수면 SK
	else if (n % 2 == 0) cout << "CY"; //짝수면 CY
	//n=2일 때 SK가 3개 가져가면 이기는 건줄 알았는데 딱 맞게 가져가야 이기는 것 같다
}
