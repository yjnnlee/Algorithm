#include <iostream>
#include <vector>
using namespace std;
int tree[1000][2];
int n;

void print(int x, int num) {
	if (num == 0) cout << (char)x;
	if (tree[x][0] != '.') print(tree[x][0], num);
	if (num == 1) cout << (char)x;
	if (tree[x][1] != '.') print(tree[x][1], num);
	if (num == 2) cout << (char)x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a][0] = b;
		tree[a][1] = c;
	}

	for (int i = 0; i < 3; i++) {
		print('A', i);
		cout << '\n';
	}
}
