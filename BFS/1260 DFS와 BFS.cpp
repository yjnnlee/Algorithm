#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
vector<vector<int>> a;
int visit[1001];
void dfs(int now) {
    visit[now] = 1;
    cout << now << " ";
    for (int i = 0; i < a[now].size(); i++) {
        if (visit[a[now][i]] == 0) dfs(a[now][i]); //정렬이 되어 있어야 함
    }
}

queue<int> q;
void bfs(int start) {
    q.push(start);
    visit[start] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";
        for (int i = 0; i < a[now].size(); i++) {
            int next = a[now][i];
            if (visit[next] == 0) {
                q.push(next);
                visit[next] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, v;
    cin >> n >> m >> v;
    a.resize(10003);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    dfs(v);
    memset(visit, 0, sizeof(visit));
    cout << "\n";
    bfs(v);
}
