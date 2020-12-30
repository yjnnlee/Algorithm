#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1001;
int a[MAX][2], n;

void go(int now, int num) {
	if (num == 0) cout << (char)now; //전위
	if(a[now][0] != '.') go(a[now][0], num); //왼 탐색
	if (num == 1) cout << (char)now; //중위
	if (a[now][1] != '.') go(a[now][1], num); //우 탐색
	if (num == 2) cout << (char)now; //후위
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		a[x][0] = y;
		a[x][1] = z;
	}
	go('A', 0); cout << "\n";
	go('A', 1); cout << "\n";
	go('A', 2); cout << "\n";
}
