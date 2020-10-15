#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> v;
bool chk[10];
int n, m;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	queue<int> q;
	for (int i = 0; i < n; i++) q.push(i + 1);

	cout << "<";
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m -1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front();
	cout << ">";
}
