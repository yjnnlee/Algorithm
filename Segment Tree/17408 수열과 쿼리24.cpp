#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void init(vector<int>& tree, vector<int>& a, int start, int end, int node) {
    if (start == end) {
        tree[node] = start;
        return;
    }
    else {
//        return tree[node] = max(init(tree, a, start, (start + end) / 2, node * 2), init(tree, a, (start + end) / 2 + 1, end, node * 2));
        init(tree, a, start, (start + end) / 2, node * 2);
        init(tree, a, (start + end) / 2 + 1, end, node * 2+1);
        if (a[tree[node * 2]] > a[tree[node * 2 + 1]]) {
            tree[node] = tree[node * 2];
        }
        else {
            tree[node] = tree[node * 2 + 1];
        }
    }
}

void update(vector<int>& tree, vector<int>& a, int start, int end, int node, int index, int diff) {
    if (index < start || end < index) return;
    if (start == end) {
        a[index] = diff;
        tree[node] = start;
        return;
    }
    update(tree, a, start, (start + end) / 2, node * 2, index, diff);
    update(tree, a, (start + end) / 2 + 1, end, node * 2 + 1, index, diff);
    if (a[tree[node * 2]] > a[tree[node * 2 + 1]]) {
        tree[node] = tree[node * 2];
    }
    else {
        tree[node] = tree[node * 2 + 1];
    }
}

int findmax(vector<int> &tree, vector<int> &a, int start, int end, int left, int right, int node) {
    if (end <left || right< start) return -1;
    if (left <= start && end <= right) return tree[node];
    else {
        int mid1 = findmax(tree, a, start, (start + end) / 2, left, right, node * 2);
        int mid2 = findmax(tree, a, (start + end) / 2 + 1, end, left, right, node * 2+1);
        if (mid1 == -1) return mid2;
        else if (mid2 == -1) return mid1;
        else {
            if (a[mid1] > a[mid2]) return mid1;
            else return mid2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int h = (int)ceil(log2(n+1));
    int th = (1 << (h + 1));
    vector<int> tree(th);
    init(tree, a, 0, n - 1, 1);
    int m;
    cin >> m;
    while (m--) {
        int what, b, c;
        cin >> what >> b >> c;
        if (what == 1) {
            b--;
            a[b] = c;
            update(tree, a, 0, n - 1, 1, b, c);
        }
        else {
            b--, c--;
            int res = 0;
            int mid = findmax(tree, a, 0, n - 1, b, c, 1);
            if (mid - 1 >= b) {
                int mid2 = findmax(tree, a, 0, n - 1, b, mid - 1, 1);
                res = max(res, a[mid] + a[mid2]);
            }
            if (mid + 1 <= c) { //mid를 찾았는데, mid2는 mid의 왼쪽에 있을 수도 있고, 오른쪽에 있을 수도 있기 때문에 if, if로 나눈다!!
                int mid2 = findmax(tree, a, 0, n - 1, mid + 1, c, 1);
                res = max(res, a[mid] + a[mid2]);
            }
            cout << res << '\n';
        }
    }
}
