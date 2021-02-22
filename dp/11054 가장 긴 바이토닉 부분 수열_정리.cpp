#include <iostream>
#include <algorithm>
using namespace std;
int dp1[2001], dp2[2001]; //i가 마지막 수인 증가하는 수열의 길이, 감소하는 수열의 길이, 바이토닉 수열
int a[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp1[i] = 1;  //만약 아래 for문에서 하나도 해당되는 수가 없어도, 1을 최고 길이로 가진다
		dp2[i] = 1;
	}
	//바이토닉 수열: n을 기준으로 가장 긴 증가수열(왼쪽), 가장 긴 감소수열(오른쪽)
	//앞에서부터 증가수열, 뒤에서부터 감소수열을 구하고 둘 값을 더해서 가장 큰 값에서 -1한다(n자신은 중복되기 때문)
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) { //본인보다 앞의 수를 보며 자기보다 작은(증가수열이 되는 수)수를 찾음
			if (a[j] < a[i]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) { //본인보다 뒤의 수를 보며 자기보다 작은(감소수열이 되는 수)수를 찾음
			if (a[j] < a[i]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	//for (int i = 0; i < n; i++) {
	//	cout << dp1[i] << " ";
	//}cout << endl;
	//for (int i = 0; i < n; i++) {
	//	cout << dp2[i] << " ";
	//}cout << endl;

	int res = 0;
	for (int i = 0; i < n; i++) {
		int tmp = dp1[i] + dp2[i];
		if (tmp > res) res = tmp;
	}
	cout << res - 1;
}

/*
7
1 4 3 2 1 5 6
답:5
*/
