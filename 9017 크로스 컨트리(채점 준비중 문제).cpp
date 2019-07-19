#include <stdio.h>
int n, m, a[1001], chk[1001], max1 = 0, max2 = 0, max_team = 1, sum = 0, score[1001], fivescore[1001];
int main() {
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);

		for(int i=0;i<m;i++){
			scanf("%d", &a[i]);
			chk[a[i]]++;
			if(max1<a[i]) max1 = a[i];
		}
		int tmp = 1, j = 1;
		for(int i=0;i<m;i++){ 
			if(chk[a[i]] == 6) {
				score[i] +=tmp;
				tmp++;
			} 
		}		
		int team = 0;
		for(int i=1;i<=max1;i++){
			if(chk[i] != 6) continue;
			for(int j=0;j<m;j++){
				if(a[j]==i&&team<=4){
					if(team==4 && chk[a[j]] == 6) {
						fivescore[i] = score[j];
//						printf("%d %d\n", fivescore[i], i);
					}
					else {
						sum += score[j];
					}
					team++;
				}
			}
			
			if(max2<sum) {
				max2 = sum;
				max_team = i;
			}
			else if(max2 == sum){
				if(fivescore[i] < fivescore[max_team]) max_team = i;
			}
//			printf("%d %d\n", fivescore[max_team], max_team);
			sum = 0;
			team = 0;
		}
		printf("%d\n", max_team);
		for(int i=0;i<m;i++){
			chk[i] = 0;
			score[i] = 0;
			fivescore[i] = 0;
		}
		max1=0; max2=0; max_team = 1; sum = 0; team = 0, max_team = 0;
		
	}
}
