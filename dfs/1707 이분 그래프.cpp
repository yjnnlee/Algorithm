#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
vector<int>a[20001];
//int a[20001][20001];
int visit[20001];
int n, m;

//1빨강 2검정
void dfs(int now) {
    if (!visit[now]) visit[now] = 1;
    for (int i = 0; i < a[now].size(); i++) {
        int next = a[now][i];
        if (!visit[next]) {
            if (visit[now] == 1) visit[next] = 2;
            else if (visit[now] == 2) visit[next] = 1;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        memset(visit, 0, sizeof(visit));
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            a[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
            //a[x][y] = a[y][x] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                dfs(i);
            }
        }

        bool flag = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                int next = a[i][j];
                if (visit[i] == visit[next]) {                   
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
