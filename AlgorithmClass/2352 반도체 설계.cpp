#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[40000], check[40000], res = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	check[0] = arr[0];
	int now = 0;

	for (int i = 1; i < n; i++) {
		if (check[now] < arr[i]) {
			now++;
			check[now] = arr[i];
		}
		else {
			int tmp = lower_bound(check, check + now, arr[i]) - check;
			check[tmp] = arr[i];

		}
	}
	
	cout <<now+1;
}

/*
6
4 2 6 3 1 5
1 2 3 4 5 6
*/