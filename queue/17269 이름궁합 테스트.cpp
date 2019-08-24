#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int alpha[] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
char name1[105], name2[105];

void solve(queue<int> a){
		if(a.size() == 2) {
			if(a.front() != 0){
				printf("%d", a.front());
			}
			a.pop();
			printf("%d%%", a.front());
			return;
		}
		
		queue<int> b;
		int alen = a.size();
		for(int i=0;i<alen-1;i++){
			int now = a.front();
			a.pop();
			now += a.front();
			b.push(now%10);
		}
		solve(b);
}

int main() {
	scanf("%d %d %s %s", &n, &m, name1, name2);
	int nlen = max(n, m);
	
	queue<int> a;
	
	for(int i=0;i<nlen;i++){
		if(i<n) a.push(alpha[name1[i]-'A']);
		if(i<m) a.push(alpha[name2[i]-'A']);
	}

	solve(a);

}
