#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int n;
struct Node {
	int left, right;
};
vector<Node> tree(1000001);

void postorder(int now) {
	if (now == 0) return;
	if (tree[now].left != 0) postorder(tree[now].left);
	if (tree[now].right != 0) postorder(tree[now].right);
	cout << now << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, root;
	cin >> root; //첫 값은 root
	while (cin >> n) { //입력이 있을 때만 반복문 실행
		int now = root; //지금 탐색 위치
		while (1) {
			if (n < now) {
				if (tree[now].left != 0) now = tree[now].left; //노드가 있으면 더 탐색
				else { //노드가 없으면 생성 후 종료
					tree[now].left = n;
					break;
				}
			}
			else {
				if (tree[now].right != 0) now = tree[now].right;
				else {
					tree[now].right = n;
					break;
				}
			}
		}
	}
	postorder(root);
}
